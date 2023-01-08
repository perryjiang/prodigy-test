#include "coordinate.h"

#include <ostream>

namespace prodigy {
std::ostream& operator<<(std::ostream& ostream, const Coordinate coordinate) {
  ostream << file_of(coordinate) << rank_of(coordinate);
  return ostream;
}
}  // namespace prodigy
