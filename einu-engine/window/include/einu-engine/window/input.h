#pragma once

#include <einu-engine/core/util/enum.h>

#include <array>
#include <bitset>
#include <glm/glm.hpp>

#include "einu-engine/window/internal/glfw_input_def.h"

namespace einu {
namespace window {
namespace input {

enum class Action : unsigned char;
enum class MouseButton : unsigned char;
enum class ModifierKeyFlag : unsigned char;
enum class KeyboardKey;
using CursorPos = glm::vec2;

template <typename T>
constexpr std::size_t GetEnumCount() noexcept;

enum class Action : unsigned char {
  Press = GLFW_PRESS,
  Release = GLFW_RELEASE,
  Repeat = GLFW_REPEAT,
};

enum class MouseButton : unsigned char {
  Button1 = GLFW_MOUSE_BUTTON_1,
  Button2 = GLFW_MOUSE_BUTTON_2,
  Button3 = GLFW_MOUSE_BUTTON_3,
  Button4 = GLFW_MOUSE_BUTTON_4,
  Button5 = GLFW_MOUSE_BUTTON_5,
  Button6 = GLFW_MOUSE_BUTTON_6,
  Button7 = GLFW_MOUSE_BUTTON_7,
  Button8 = GLFW_MOUSE_BUTTON_8,
  ButtonLast = GLFW_MOUSE_BUTTON_8,
  ButtonLeft = GLFW_MOUSE_BUTTON_1,
  ButtonRight = GLFW_MOUSE_BUTTON_2,
  ButtonMiddle = GLFW_MOUSE_BUTTON_3,
};

enum class ModifierKeyFlag : unsigned char {
  Shift = GLFW_MOD_SHIFT,
  Control = GLFW_MOD_CONTROL,
  Alt = GLFW_MOD_ALT,
  Super = GLFW_MOD_SUPER,
  CapsLock = GLFW_MOD_CAPS_LOCK,
  NumLock = GLFW_MOD_NUM_LOCK,
};

enum class KeyboardKey {
  Unknown = GLFW_KEY_UNKNOWN,
  Space = GLFW_KEY_SPACE,
  Apostrophe = GLFW_KEY_APOSTROPHE,
  Comma = GLFW_KEY_COMMA,
  Minus = GLFW_KEY_MINUS,
  Period = GLFW_KEY_PERIOD,
  Slash = GLFW_KEY_SLASH,
  Alpha0 = GLFW_KEY_0,
  Alpha1 = GLFW_KEY_1,
  Alpha2 = GLFW_KEY_2,
  Alpha3 = GLFW_KEY_3,
  Alpha4 = GLFW_KEY_4,
  Alpha5 = GLFW_KEY_5,
  Alpha6 = GLFW_KEY_6,
  Alpha7 = GLFW_KEY_7,
  Alpha8 = GLFW_KEY_8,
  Alpha9 = GLFW_KEY_9,
  Semicolon = GLFW_KEY_SEMICOLON,
  Equal = GLFW_KEY_A,
  B = GLFW_KEY_B,
  C = GLFW_KEY_C,
  D = GLFW_KEY_D,
  E = GLFW_KEY_E,
  F = GLFW_KEY_F,
  G = GLFW_KEY_G,
  H = GLFW_KEY_H,
  I = GLFW_KEY_I,
  J = GLFW_KEY_J,
  K = GLFW_KEY_K,
  L = GLFW_KEY_L,
  M = GLFW_KEY_M,
  N = GLFW_KEY_N,
  O = GLFW_KEY_O,
  P = GLFW_KEY_P,
  Q = GLFW_KEY_Q,
  R = GLFW_KEY_R,
  S = GLFW_KEY_S,
  T = GLFW_KEY_T,
  U = GLFW_KEY_U,
  V = GLFW_KEY_V,
  W = GLFW_KEY_W,
  X = GLFW_KEY_X,
  Y = GLFW_KEY_Y,
  Z = GLFW_KEY_Z,
  LeftBracket = GLFW_KEY_LEFT_BRACKET,
  Backslash = GLFW_KEY_BACKSLASH,
  RightBracket = GLFW_KEY_RIGHT_BRACKET,
  GraveAccent = GLFW_KEY_GRAVE_ACCENT,
  World1 = GLFW_KEY_WORLD_1,
  World2 = GLFW_KEY_WORLD_2,
  Escape = GLFW_KEY_ESCAPE,
  Enter = GLFW_KEY_ENTER,
  Tab = GLFW_KEY_TAB,
  Backspace = GLFW_KEY_BACKSPACE,
  Insert = GLFW_KEY_INSERT,
  Delete = GLFW_KEY_DELETE,
  Right = GLFW_KEY_RIGHT,
  Left = GLFW_KEY_LEFT,
  Down = GLFW_KEY_DOWN,
  Up = GLFW_KEY_UP,
  PageUp = GLFW_KEY_PAGE_UP,
  PageDown = GLFW_KEY_PAGE_DOWN,
  Home = GLFW_KEY_HOME,
  End = GLFW_KEY_END,
  CapsLock = GLFW_KEY_CAPS_LOCK,
  ScrollLock = GLFW_KEY_SCROLL_LOCK,
  NumLock = GLFW_KEY_NUM_LOCK,
  PrintScreen = GLFW_KEY_PRINT_SCREEN,
  Pause = GLFW_KEY_PAUSE,
  F1 = GLFW_KEY_F1,
  F2 = GLFW_KEY_F2,
  F3 = GLFW_KEY_F3,
  F4 = GLFW_KEY_F4,
  F5 = GLFW_KEY_F5,
  F6 = GLFW_KEY_F6,
  F7 = GLFW_KEY_F7,
  F8 = GLFW_KEY_F8,
  F9 = GLFW_KEY_F9,
  F10 = GLFW_KEY_F10,
  F11 = GLFW_KEY_F11,
  F12 = GLFW_KEY_F12,
  F13 = GLFW_KEY_F13,
  F14 = GLFW_KEY_F14,
  F15 = GLFW_KEY_F15,
  F16 = GLFW_KEY_F16,
  F17 = GLFW_KEY_F17,
  F18 = GLFW_KEY_F18,
  F19 = GLFW_KEY_F19,
  F20 = GLFW_KEY_F20,
  F21 = GLFW_KEY_F21,
  F22 = GLFW_KEY_F22,
  F23 = GLFW_KEY_F23,
  F24 = GLFW_KEY_F24,
  F25 = GLFW_KEY_F25,
  Keypad0 = GLFW_KEY_KP_0,
  Keypad1 = GLFW_KEY_KP_1,
  Keypad2 = GLFW_KEY_KP_2,
  Keypad3 = GLFW_KEY_KP_3,
  Keypad4 = GLFW_KEY_KP_4,
  Keypad5 = GLFW_KEY_KP_5,
  Keypad6 = GLFW_KEY_KP_6,
  Keypad7 = GLFW_KEY_KP_7,
  Keypad8 = GLFW_KEY_KP_8,
  Keypad9 = GLFW_KEY_KP_9,
  KeypadDecimal = GLFW_KEY_KP_DECIMAL,
  KeypadDivide = GLFW_KEY_KP_DIVIDE,
  KeypadMultiply = GLFW_KEY_KP_MULTIPLY,
  KeypadSubtract = GLFW_KEY_KP_SUBTRACT,
  KeypadAdd = GLFW_KEY_KP_ADD,
  KeypadEnter = GLFW_KEY_KP_ENTER,
  KeypadEqual = GLFW_KEY_KP_EQUAL,
  LeftShift = GLFW_KEY_LEFT_SHIFT,
  LeftControl = GLFW_KEY_LEFT_CONTROL,
  LeftAlt = GLFW_KEY_LEFT_ALT,
  LeftSuper = GLFW_KEY_LEFT_SUPER,
  RightShift = GLFW_KEY_RIGHT_SHIFT,
  RightControl = GLFW_KEY_RIGHT_CONTROL,
  RightAlt = GLFW_KEY_RIGHT_ALT,
  RightSuper = GLFW_KEY_RIGHT_SUPER,
  Menu = GLFW_KEY_MENU,
  Last = GLFW_KEY_LAST,
};

template <>
inline constexpr std::size_t GetEnumCount<MouseButton>() noexcept {
  return static_cast<std::size_t>(MouseButton::ButtonLast) + 1;
}

template <>
inline constexpr std::size_t GetEnumCount<KeyboardKey>() noexcept {
  return static_cast<std::size_t>(KeyboardKey::Last) + 1;
}

struct InputBuffer {
  static constexpr std::size_t kInputBufferSize = 8;
  using BoolBuffer = std::bitset<kInputBufferSize>;
  using MouseButtonBuffer = BoolBuffer;
  using KeyboardKeyBuffer = BoolBuffer;
  using ModifierKeyBuffer = std::array<ModifierKeyFlag, kInputBufferSize>;
  using CursorPosBuffer = std::array<CursorPos, kInputBufferSize>;

  template <typename T>
  using BufferMap = std::array<BoolBuffer, GetEnumCount<T>()>;
  using MouseButtonBufferMap = BufferMap<MouseButton>;
  using KeyboardKeyBufferMap = BufferMap<KeyboardKey>;
  MouseButtonBufferMap mouse_button_buffer_table{};
  KeyboardKeyBufferMap keyboard_key_buffer_table{};
  ModifierKeyBuffer modifier_key_buffer{};
  CursorPosBuffer cursor_pos_buffer{};

  std::size_t cursor = 0;

  bool GetMouseButton(MouseButton button) const noexcept {
    return GetMouseButtonBuffer(button)[cursor];
  }

  MouseButtonBuffer::reference GetMouseButton(MouseButton button) noexcept {
    return GetMouseButtonBuffer(button)[cursor];
  }

  bool GetKeyboardKey(KeyboardKey key) const noexcept {
    return GetKeyboadKeyBuffer(key)[cursor];
  }

  KeyboardKeyBuffer::reference GetKeyboardKey(KeyboardKey key) noexcept {
    return GetKeyboadKeyBuffer(key)[cursor];
  }

  ModifierKeyFlag GetModifierKeyFlag() const noexcept {
    return modifier_key_buffer[cursor];
  }

  ModifierKeyFlag& GetModifierKeyFlag() noexcept {
    return modifier_key_buffer[cursor];
  }

  CursorPos GetCursorPos() const noexcept { return cursor_pos_buffer[cursor]; }
  CursorPos& GetCursorPos() noexcept { return cursor_pos_buffer[cursor]; }

  const BoolBuffer& GetMouseButtonBuffer(MouseButton button) const noexcept {
    return mouse_button_buffer_table
        [static_cast<MouseButtonBufferMap::size_type>(button)];
  }

  BoolBuffer& GetMouseButtonBuffer(MouseButton button) noexcept {
    return mouse_button_buffer_table
        [static_cast<MouseButtonBufferMap::size_type>(button)];
  }

  const BoolBuffer& GetKeyboadKeyBuffer(KeyboardKey key) const noexcept {
    return keyboard_key_buffer_table
        [static_cast<KeyboardKeyBufferMap::size_type>(key)];
  }

  BoolBuffer& GetKeyboadKeyBuffer(KeyboardKey key) noexcept {
    return keyboard_key_buffer_table
        [static_cast<KeyboardKeyBufferMap::size_type>(key)];
  }
};

}  // namespace input
}  // namespace window

namespace util {

template <>
struct EnableBitMaskOperators<window::input::ModifierKeyFlag> {
  static constexpr bool enable = true;
};

}  // namespace util
}  // namespace einu
