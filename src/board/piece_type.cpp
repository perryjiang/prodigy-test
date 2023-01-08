#include "piece_type.h"

#include <ostream>

namespace prodigy {
std::ostream& operator<<(std::ostream& ostream, const PieceType piece_type) {
  switch (piece_type) {
    case PieceType::PAWN:
      ostream << 'p';
      break;
    case PieceType::KNIGHT:
      ostream << 'n';
      break;
    case PieceType::BISHOP:
      ostream << 'b';
      break;
    case PieceType::ROOK:
      ostream << 'r';
      break;
    case PieceType::QUEEN:
      ostream << 'q';
      break;
    case PieceType::KING:
      ostream << 'k';
      break;
  }
  return ostream;
}
}  // namespace prodigy
