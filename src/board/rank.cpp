#include "rank.h"

#include <ostream>
#include <utility>

namespace prodigy {
std::ostream& operator<<(std::ostream& ostream, const Rank rank) {
  ostream << static_cast<char>('1' + std::to_underlying(rank));
  return ostream;
}
}  // namespace prodigy
