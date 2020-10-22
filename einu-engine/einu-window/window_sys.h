#pragma once

#include <einu-core/entity_view.h>

#include "einu-window/window_comp.h"

namespace einu {
namespace window {
namespace sys {

void Init();

void Create(comp::Window& win);

void UpdateInput(comp::Window& win);

}  // namespace sys
}  // namespace window
}  // namespace einu