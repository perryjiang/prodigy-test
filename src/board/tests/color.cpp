#define BOOST_TEST_MODULE Color

#include "board/color.h"

#include <boost/test/tools/output_test_stream.hpp>
#include <boost/test/unit_test.hpp>

namespace prodigy {
namespace {
static_assert(sizeof(Color) == 1);

static_assert(to_color('w') == Color::WHITE);
static_assert(to_color('b') == Color::BLACK);

static_assert(~Color::WHITE == Color::BLACK);
static_assert(~Color::BLACK == Color::WHITE);

BOOST_AUTO_TEST_CASE(ostream) {
  boost::test_tools::output_test_stream ostream;
  ostream << Color::WHITE;
  BOOST_TEST(ostream.is_equal("w"));
  ostream << Color::BLACK;
  BOOST_TEST(ostream.is_equal("b"));
}
}  // namespace
}  // namespace prodigy
