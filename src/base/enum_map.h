#pragma once

#include <array>
#include <type_traits>
#include <utility>

#include "enum_traits.h"

namespace prodigy {
template <typename E, typename T>
  requires std::is_enum_v<E>
class EnumMap : private std::array<T, EnumTraits<E>::COUNT> {
  using Base = std::array<T, EnumTraits<E>::COUNT>;

 public:
  constexpr typename Base::reference operator[](const E enumerator) { return (*this)[std::to_underlying(enumerator)]; }

  constexpr typename Base::const_reference operator[](const E enumerator) const {
    return (*this)[std::to_underlying(enumerator)];
  }

 private:
  using Base::operator[];
};
}  // namespace prodigy
