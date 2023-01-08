#include <unistd.h>

#include <boost/asio/awaitable.hpp>
#include <boost/asio/buffers_iterator.hpp>
#include <boost/asio/co_spawn.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/posix/stream_descriptor.hpp>
#include <boost/asio/read_until.hpp>
#include <boost/asio/signal_set.hpp>
#include <boost/asio/streambuf.hpp>
#include <boost/asio/use_awaitable.hpp>
#include <csignal>
#include <cstddef>
#include <exception>
#include <iostream>
#include <string>

#include "core/engine.h"

int main() {
  try {
    boost::asio::io_context io_context(1);
    boost::asio::signal_set signal_set(io_context, SIGTERM, SIGINT);
    signal_set.async_wait([&](auto&&...) { io_context.stop(); });
    boost::asio::co_spawn(
        io_context,
        [&io_context] -> boost::asio::awaitable<void> {
          boost::asio::posix::stream_descriptor stream_descriptor(io_context, ::dup(STDIN_FILENO));
          boost::asio::streambuf streambuf;
          prodigy::Engine engine(io_context);
          while (true) {
            const auto bytes_transferred =
                co_await boost::asio::async_read_until(stream_descriptor, streambuf, '\n', boost::asio::use_awaitable);
            engine.handle(std::string(
                boost::asio::buffers_begin(streambuf.data()),
                boost::asio::buffers_begin(streambuf.data()) + static_cast<std::ptrdiff_t>(bytes_transferred)));
            streambuf.consume(bytes_transferred);
          }
        },
        [](const std::exception_ptr& exception_ptr) {
          if (exception_ptr) {
            std::rethrow_exception(exception_ptr);
          }
        });
    io_context.run();
  } catch (const std::exception& exception) {
    std::clog << exception.what() << '\n';
    return 1;
  }
}
