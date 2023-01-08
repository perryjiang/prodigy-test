#include "uci.h"

#include <algorithm>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/constants.hpp>
#include <boost/algorithm/string/split.hpp>
#include <deque>
#include <functional>
#include <iterator>
#include <unordered_map>

#include "fen/fen.h"

namespace prodigy::uci {
Command parse(const std::string_view command) {
  std::deque<std::string_view> tokens;
  boost::split(tokens, command, boost::is_space(), boost::token_compress_on);
  if (tokens.front().empty()) {
    tokens.pop_front();
  }
  if (tokens.back().empty()) {
    tokens.pop_back();
  }
  const std::unordered_map<std::string_view, std::function<Command()>> parsers = {{
      {"uci", [] { return UCI(); }},
      {"debug", [&] { return Debug{.on = tokens.front() == "on"}; }},
      {"isready", [] { return IsReady(); }},
      {"setoption",
       [&] {
         const auto value_iterator = std::find(tokens.cbegin(), tokens.cend(), "value");
         SetOption set_option{
             .name = std::string(tokens.front().data(), std::prev(value_iterator)->end()),
         };
         if (value_iterator != tokens.cend()) {
           set_option.value.emplace(std::next(value_iterator)->begin(), std::prev(tokens.cend())->end());
         }
         return set_option;
       }},
      {"register", [] { return Register(); }},
      {"ucinewgame", [] { return UCINewGame(); }},
      {"position",
       [&] {
         return Position{.fen = std::string(tokens.front() == "fen" ? tokens[1] : fen::STARTING_POSITION),
                         .moves = {++std::find(tokens.cbegin(), tokens.cend(), "moves"), tokens.cend()}};
       }},
      {"go",
       [] {
         // TODO
         return Go();
       }},
      {"stop", [] { return Stop(); }},
      {"ponderhit", [] { return PonderHit(); }},
      {"quit", [] { return Quit(); }},
  }};
  while (!tokens.empty()) {
    const auto token = tokens.front();
    tokens.pop_front();
    if (const auto iterator = parsers.find(token); iterator != parsers.end()) {
      return iterator->second();
    }
  }
  return {};
}
}  // namespace prodigy::uci
