#pragma once

#include <boost/assert.hpp>
#include <cstdint>
#include <iosfwd>

#include "base/enum_traits.h"

namespace prodigy {
enum class PieceType : std::uint8_t {
  PAWN,
  KNIGHT,
  BISHOP,
  ROOK,
  QUEEN,
  KING,
};

template <>
struct EnumTraits<PieceType> {
  static constexpr auto COUNT = 6UZ;
};

constexpr PieceType to_piece_type(const char piece_type) {
  switch (piece_type) {
    case 'p':
      return PieceType::PAWN;
    case 'n':
      return PieceType::KNIGHT;
    case 'b':
      return PieceType::BISHOP;
    case 'r':
      return PieceType::ROOK;
    case 'q':
      return PieceType::QUEEN;
    case 'k':
      return PieceType::KING;
    default:
      BOOST_ASSERT(false);
      __builtin_unreachable();
  }
}

std::ostream& operator<<(std::ostream&, PieceType);
}  // namespace prodigy
