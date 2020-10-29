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

#pragma once

#include <einu-engine/core/eid.h>
#include <einu-engine/core/xnent.h>

#include <glm/glm.hpp>
#include <vector>

namespace astar {
namespace cmp {

struct Cell : public einu::Xnent {
  glm::ivec2 pos;
};

struct Starchaser : public einu::Xnent {
  enum class State { Collecting, Selling, GoingHome };
  State state = State::Collecting;
};

struct StarPocket : public einu::Xnent {
  einu::EID star_eid = ~einu::EID{0};
};

struct Energy : public einu::Xnent {
  float energy = 100.f;
  float fatigue_threshold = 50.f;
  float max_energy = 100.f;
};

struct PathFinding : public einu::Xnent {
  struct Node {
    glm::uvec2 pos;
    Node* parent = nullptr;
    float f = 0.0f;
  };

  using NodeList = std::vector<Node>;

  NodeList open_list;
  NodeList closed_list;
  Node destination;
  std::vector<glm::uvec2> path;
};

}  // namespace cmp
}  // namespace astar
