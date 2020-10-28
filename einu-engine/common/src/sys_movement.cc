// Copyright (C) 2020  Xiaoyue Chen
//
// This file is part of EINU Engine.
// See <https://github.com/xiaoyuechen/einu.git>.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include "einu-engine/common/sys_movement.h"

namespace einu {
namespace common {
namespace sys {

void Move(cmp::Transform& transform, cmp::Movement& movement,
          const sgl::Time& time) {
  auto dp = movement.direction * movement.speed * sgl::DeltaSeconds(time);
  transform.SetPosition(transform.GetPosition() + dp);
}

}  // namespace sys
}  // namespace common
}  // namespace einu