#define BOOST_TEST_MODULE File

#include "board/file.h"

#include <boost/test/tools/output_test_stream.hpp>
#include <boost/test/unit_test.hpp>

namespace prodigy {
namespace {
static_assert(sizeof(File) == 1);

static_assert(to_file('a') == File::A);
static_assert(to_file('b') == File::B);
static_assert(to_file('c') == File::C);
static_assert(to_file('d') == File::D);
static_assert(to_file('e') == File::E);
static_assert(to_file('f') == File::F);
static_assert(to_file('g') == File::G);
static_assert(to_file('h') == File::H);

BOOST_AUTO_TEST_CASE(ostream) {
  boost::test_tools::output_test_stream ostream;
  ostream << File::A;
  BOOST_TEST(ostream.is_equal("a"));
  ostream << File::B;
  BOOST_TEST(ostream.is_equal("b"));
  ostream << File::C;
  BOOST_TEST(ostream.is_equal("c"));
  ostream << File::D;
  BOOST_TEST(ostream.is_equal("d"));
  ostream << File::E;
  BOOST_TEST(ostream.is_equal("e"));
  ostream << File::F;
  BOOST_TEST(ostream.is_equal("f"));
  ostream << File::G;
  BOOST_TEST(ostream.is_equal("g"));
  ostream << File::H;
  BOOST_TEST(ostream.is_equal("h"));
}
}  // namespace
}  // namespace prodigy
