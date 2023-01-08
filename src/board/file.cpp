#include "file.h"

#include <ostream>
#include <utility>

namespace prodigy {
std::ostream& operator<<(std::ostream& ostream, const File file) {
  ostream << static_cast<char>('a' + std::to_underlying(file));
  return ostream;
}
}  // namespace prodigy
