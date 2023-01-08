#include "engine.h"

#include <boost/asio/io_context.hpp>
#include <variant>

#include "uci/uci.h"

namespace prodigy {
Engine::Engine(boost::asio::io_context& io_context) : io_context_(io_context) {}

namespace {
template <typename... Ts>
struct visitor : Ts... {
  using Ts::operator()...;
};
template <typename... Ts>
visitor(Ts...) -> visitor<Ts...>;
}  // namespace

void Engine::handle(const std::string_view uci_command) {
  // TODO
  std::visit(visitor{
                 [](std::monostate) {},
                 [](uci::UCI) {},
                 [&](const uci::Debug debug) { debug_ = debug.on; },
                 [](uci::IsReady) {},
                 [](uci::SetOption&&) {},
                 [](uci::Register) {},
                 [](uci::UCINewGame) {},
                 [](uci::Position&&) {},
                 [](uci::Go&&) {},
                 [](uci::Stop) {},
                 [](uci::PonderHit) {},
                 [&](uci::Quit) { io_context_.stop(); },
             },
             uci::parse(uci_command));
}
}  // namespace prodigy
