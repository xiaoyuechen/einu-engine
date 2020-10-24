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

#include <einu-engine/core/internal/xnent_type_id_register.h>
#include <gtest/gtest.h>

#include "xnents.h"

namespace einu {
namespace internal {

TEST(XnentTypeIDRegisterTest, _) {
  using XnentList = XnentList<C0, C1, C2>;

  {
    XnentTypeIDRegister<XnentList> reg;
    EXPECT_EQ(GetXnentTypeID<C0>(), 0);
    EXPECT_EQ(GetXnentTypeID<C1>(), 1);
    EXPECT_EQ(GetXnentTypeID<C2>(), 2);
  }

  EXPECT_EQ(GetXnentTypeID<C0>(), XnentTypeID{});
  EXPECT_EQ(GetXnentTypeID<C1>(), XnentTypeID{});
  EXPECT_EQ(GetXnentTypeID<C2>(), XnentTypeID{});
}

}  // namespace internal
}  // namespace einu
