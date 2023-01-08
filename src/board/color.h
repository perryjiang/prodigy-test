#pragma once

#include <boost/assert.hpp>
#include <cstdint>
#include <iosfwd>
#include <utility>

#include "base/enum_traits.h"

namespace prodigy {
enum class Color : std::uint8_t {
  WHITE,
  BLACK,
};

template <>
struct EnumTraits<Color> {
  static constexpr auto COUNT = 2UZ;
};

constexpr Color to_color(const char color) {
  BOOST_ASSERT(color == 'w' || color == 'b');
  return color == 'w' ? Color::WHITE : Color::BLACK;
}

constexpr Color operator~(const Color color) { return static_cast<Color>(std::to_underlying(color) ^ 1); }

std::ostream& operator<<(std::ostream&, Color);
}  // namespace prodigy
