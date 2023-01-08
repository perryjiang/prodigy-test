#include "color.h"

#include <ostream>

namespace prodigy {
std::ostream& operator<<(std::ostream& ostream, const Color color) {
  ostream << (color == Color::WHITE ? 'w' : 'b');
  return ostream;
}
}  // namespace prodigy
