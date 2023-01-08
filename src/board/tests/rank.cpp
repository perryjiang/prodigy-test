#define BOOST_TEST_MODULE File

#include "board/rank.h"

#include <boost/test/tools/output_test_stream.hpp>
#include <boost/test/unit_test.hpp>

namespace prodigy {
namespace {
static_assert(sizeof(Rank) == 1);

static_assert(to_rank('1') == Rank::ONE);
static_assert(to_rank('2') == Rank::TWO);
static_assert(to_rank('3') == Rank::THREE);
static_assert(to_rank('4') == Rank::FOUR);
static_assert(to_rank('5') == Rank::FIVE);
static_assert(to_rank('6') == Rank::SIX);
static_assert(to_rank('7') == Rank::SEVEN);
static_assert(to_rank('8') == Rank::EIGHT);

BOOST_AUTO_TEST_CASE(output_stream) {
  boost::test_tools::output_test_stream ostream;
  ostream << Rank::ONE;
  BOOST_TEST(ostream.is_equal("1"));
  ostream << Rank::TWO;
  BOOST_TEST(ostream.is_equal("2"));
  ostream << Rank::THREE;
  BOOST_TEST(ostream.is_equal("3"));
  ostream << Rank::FOUR;
  BOOST_TEST(ostream.is_equal("4"));
  ostream << Rank::FIVE;
  BOOST_TEST(ostream.is_equal("5"));
  ostream << Rank::SIX;
  BOOST_TEST(ostream.is_equal("6"));
  ostream << Rank::SEVEN;
  BOOST_TEST(ostream.is_equal("7"));
  ostream << Rank::EIGHT;
  BOOST_TEST(ostream.is_equal("8"));
}
}  // namespace
}  // namespace prodigy
