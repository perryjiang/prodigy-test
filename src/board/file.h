#pragma once

#include <boost/assert.hpp>
#include <cstdint>
#include <iosfwd>

#include "base/enum_traits.h"

namespace prodigy {
enum class File : std::uint8_t {
  A,
  B,
  C,
  D,
  E,
  F,
  G,
  H,
};

template <>
struct EnumTraits<File> {
  static constexpr auto COUNT = 8UZ;
};

constexpr File to_file(const char file) {
  BOOST_ASSERT('a' <= file && file <= 'h');
  return static_cast<File>(file - 'a');
}

std::ostream& operator<<(std::ostream&, File);
}  // namespace prodigy
