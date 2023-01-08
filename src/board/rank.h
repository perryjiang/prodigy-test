#pragma once

#include <boost/assert.hpp>
#include <cstdint>
#include <iosfwd>

#include "base/enum_traits.h"

namespace prodigy {
enum class Rank : std::uint8_t {
  ONE,
  TWO,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT,
};

template <>
struct EnumTraits<Rank> {
  static constexpr auto COUNT = 8UZ;
};

constexpr Rank to_rank(const char rank) {
  BOOST_ASSERT('1' <= rank && rank <= '8');
  return static_cast<Rank>(rank - '1');
}

std::ostream& operator<<(std::ostream&, Rank);
}  // namespace prodigy
