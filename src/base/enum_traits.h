#pragma once

#include <type_traits>

namespace prodigy {
template <typename E>
  requires std::is_enum_v<E>
struct EnumTraits;
}  // namespace prodigy
