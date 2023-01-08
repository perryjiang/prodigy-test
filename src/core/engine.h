#pragma once

#include <string_view>

namespace boost::asio {
class io_context;
}  // namespace boost::asio

namespace prodigy {
class Engine {
 public:
  explicit Engine(boost::asio::io_context&);

  void handle(std::string_view uci_command);

 private:
  boost::asio::io_context& io_context_;
  bool debug_ = false;
};
}  // namespace prodigy
