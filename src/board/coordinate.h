#pragma once

#include <concepts>
#include <cstdint>
#include <functional>
#include <iosfwd>
#include <utility>

#include "base/enum_traits.h"
#include "file.h"
#include "rank.h"

namespace prodigy {
enum class Coordinate : std::uint8_t {
  A1,
  B1,
  C1,
  D1,
  E1,
  F1,
  G1,
  H1,
  A2,
  B2,
  C2,
  D2,
  E2,
  F2,
  G2,
  H2,
  A3,
  B3,
  C3,
  D3,
  E3,
  F3,
  G3,
  H3,
  A4,
  B4,
  C4,
  D4,
  E4,
  F4,
  G4,
  H4,
  A5,
  B5,
  C5,
  D5,
  E5,
  F5,
  G5,
  H5,
  A6,
  B6,
  C6,
  D6,
  E6,
  F6,
  G6,
  H6,
  A7,
  B7,
  C7,
  D7,
  E7,
  F7,
  G7,
  H7,
  A8,
  B8,
  C8,
  D8,
  E8,
  F8,
  G8,
  H8,
};

template <>
struct EnumTraits<Coordinate> {
  static constexpr auto COUNT = 64UZ;
};

constexpr Coordinate to_coordinate(const File file, const Rank rank) {
  return static_cast<Coordinate>(std::to_underlying(rank) * EnumTraits<File>::COUNT + std::to_underlying(file));
}

constexpr File file_of(const Coordinate coordinate) {
  return static_cast<File>(std::to_underlying(coordinate) % EnumTraits<File>::COUNT);
}

constexpr Rank rank_of(const Coordinate coordinate) {
  return static_cast<Rank>(std::to_underlying(coordinate) / EnumTraits<File>::COUNT);
}

constexpr void for_each_coordinate(std::invocable<Coordinate> auto&& callback) {
  for (auto coordinate = 0UZ; coordinate < EnumTraits<Coordinate>::COUNT; ++coordinate) {
    std::invoke(std::forward<decltype(callback)>(callback), static_cast<Coordinate>(coordinate));
  }
}

std::ostream& operator<<(std::ostream&, Coordinate);
}  // namespace prodigy
