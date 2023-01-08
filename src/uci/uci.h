#pragma once

#include <chrono>
#include <cstddef>
#include <optional>
#include <string>
#include <string_view>
#include <variant>
#include <vector>

namespace prodigy::uci {
struct UCI {};

struct Debug {
  bool on;
};

struct IsReady {};

struct SetOption {
  std::string name;
  std::optional<std::string> value;
};

struct Register {};

struct UCINewGame {};

struct Position {
  std::string fen;
  std::vector<std::string> moves;
};

struct Go {
  std::vector<std::string> search_moves;
  bool ponder = false;
  std::optional<std::chrono::milliseconds> wtime;
  std::optional<std::chrono::milliseconds> btime;
  std::optional<std::chrono::milliseconds> winc;
  std::optional<std::chrono::milliseconds> binc;
  std::optional<std::size_t> moves_to_go;
  std::optional<std::size_t> depth;
  std::optional<std::size_t> nodes;
  std::optional<std::size_t> mate;
  std::optional<std::chrono::milliseconds> move_time;
  bool infinite = false;
};

struct Stop {};

struct PonderHit {};

struct Quit {};

using Command = std::variant<std::monostate, UCI, Debug, IsReady, SetOption, Register, UCINewGame, Position, Go, Stop,
                             PonderHit, Quit>;

[[nodiscard]] Command parse(std::string_view);
}  // namespace prodigy::uci
