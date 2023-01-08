#define BOOST_TEST_MODULE PieceType

#include "board/piece_type.h"

#include <boost/test/tools/output_test_stream.hpp>
#include <boost/test/unit_test.hpp>

namespace prodigy {
namespace {
static_assert(sizeof(PieceType) == 1);

static_assert(to_piece_type('p') == PieceType::PAWN);
static_assert(to_piece_type('n') == PieceType::KNIGHT);
static_assert(to_piece_type('b') == PieceType::BISHOP);
static_assert(to_piece_type('r') == PieceType::ROOK);
static_assert(to_piece_type('q') == PieceType::QUEEN);
static_assert(to_piece_type('k') == PieceType::KING);

BOOST_AUTO_TEST_CASE(output_stream) {
  boost::test_tools::output_test_stream ostream;
  ostream << PieceType::PAWN;
  BOOST_TEST(ostream.is_equal("p"));
  ostream << PieceType::KNIGHT;
  BOOST_TEST(ostream.is_equal("n"));
  ostream << PieceType::BISHOP;
  BOOST_TEST(ostream.is_equal("b"));
  ostream << PieceType::ROOK;
  BOOST_TEST(ostream.is_equal("r"));
  ostream << PieceType::QUEEN;
  BOOST_TEST(ostream.is_equal("q"));
  ostream << PieceType::KING;
  BOOST_TEST(ostream.is_equal("k"));
}
}  // namespace
}  // namespace prodigy
