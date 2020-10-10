#pragma once

#include <cassert>
#include <functional>
#include <memory>
#include <numeric>
#include <optional>
#include <vector>

#include "einu-util/bit.h"

namespace einu {
namespace util {

template <typename T>
class FixedPool {
 public:
  using size_type = std::size_t;
  using value_type = T;

  explicit FixedPool(size_type count)
      : object_arr_(count)
      , bit_arr_(count, true) {}

  FixedPool(size_type count, const T& value)
      : object_arr_(count, value)
      , bit_arr_(count, true) {}

  FixedPool(const FixedPool&) = delete;
  FixedPool& operator=(const FixedPool&) = delete;
  FixedPool(FixedPool&&) = default;
  FixedPool& operator=(FixedPool&&) = default;

  size_type Size() const noexcept { return object_arr_.size(); }
  size_type FreePos() const noexcept {
    return FindFirstSet(bit_arr_.begin(), bit_arr_.end());
  }

  bool Has(const T& obj) const noexcept {
    auto idx = &obj - object_arr_.data();
    return 0 <= idx && (unsigned)idx < Size();
  }

  [[nodiscard]] T& Acquire() noexcept {
    auto free_pos = FreePos();
    assert(free_pos != bit_arr_.size() && "no object available");
    bit_arr_[free_pos] = false;
    return object_arr_[free_pos];
  }

  [[nodiscard]] T& Acquire(size_type pos_hint) noexcept {
    assert(bit_arr_[pos_hint] && "object at pos is not available");
    bit_arr_[pos_hint] = false;
    return object_arr_[pos_hint];
  }

  void Release(const T& obj) noexcept {
    auto idx = &obj - object_arr_.data();
    assert(!bit_arr_[idx] && "object is already released");
    bit_arr_[idx] = true;
  }

 private:
  std::vector<T> object_arr_;
  std::vector<bool> bit_arr_;
};

template <typename T>
bool AllAcquired(const FixedPool<T>& pool) noexcept {
  return pool.FreePos() == pool.Size();
}

template <typename T>
class IGrowPolicy {
 public:
  using size_type = std::size_t;

  virtual ~IGrowPolicy() = default;
  virtual size_type GetGrowSize(size_type old_size) const noexcept = 0;
  virtual const T& GetValue() const noexcept = 0;
};

/**
 * This policy will double the pool size when growing is required
 * Also constructs objects with default constructor
 */
template <typename T>
class DefaultGrowPolicy : public IGrowPolicy<T> {
 public:
  virtual size_type GetGrowSize(
      size_type old_size) const noexcept override final {
    return old_size;
  }

  virtual const T& GetValue() const noexcept override final { return value_; }

 private:
  T value_{};
};

template <typename T>
class DynamicPool {
 public:
  using size_type = std::size_t;
  using value_type = T;
  using GrowPolicyPtr = std::unique_ptr<IGrowPolicy<T>>;

  explicit DynamicPool(
      size_type count,
      GrowPolicyPtr grow_policy = std::make_unique<DefaultGrowPolicy<T>>()) {
    grow_policy_ = std::move(grow_policy);
    Grow(count, grow_policy_->GetValue());
  }

  void SetGrowPolicy(GrowPolicyPtr grow_policy) noexcept {
    grow_policy_ = std::move(grow_policy);
  }

  [[nodiscard]] T& Acquire() {
    if (PoolsAllAcquired()) {
      Grow(grow_policy_->GetGrowSize(Size()), grow_policy_->GetValue());
    }

    for (auto& pool : pools_) {
      auto free_pos = pool.FreePos();
      if (free_pos != pool.Size()) {
        return pool.Acquire(free_pos);
      }
    }
    assert(false);
    return pools_[0].Acquire();
  }

  void Release(const T& obj) noexcept {
    for (auto& pool : pools_) {
      if (pool.Has(obj)) {
        pool.Release(obj);
        return;
      }
    }
    assert(false && "object does not belong to this pool");
  }

  size_type Size() const noexcept {
    return std::accumulate(
        pools_.begin(), pools_.end(), size_type{0},
        [](auto acc, const auto& pool) { return acc + pool.Size(); });
  }

 private:
  using FixedPool = FixedPool<T>;
  using PoolList = std::vector<FixedPool>;

  bool PoolsAllAcquired() const noexcept {
    for (const auto& pool : pools_) {
      if (!AllAcquired(pool)) return false;
    }
    return true;
  }

  void Grow(size_type size, const T& value) {
    if (size == 0) return;
    pools_.emplace_back(size, value);
  }

  GrowPolicyPtr grow_policy_;
  PoolList pools_;
};

}  // namespace util
}  // namespace einu