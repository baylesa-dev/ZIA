/*
** EPITECH PROJECT, 2019
** CPP_zia_2018
** File description:
** [log module] Request handler definition
*/

#pragma once

#include <iostream>
#include <chrono>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/asio/ssl/stream.hpp>
#include "Zia/API.hpp"

using boost::asio::ip::tcp;
using tls_socket = boost::asio::ssl::stream<tcp::socket&>;

namespace Zia
{
namespace Modules
{

class SSLRequestHandler : public API::RequestHandler
{
  public:
    API::HookResultType onConnectionStart(const API::Connection &conn, tcp::socket &sock) override
    {
        _socket = std::make_unique<tls_socket>(sock, *_context);
        boost::system::error_code error;
        _socket->handshake(boost::asio::ssl::stream_base::server, error);

        if (error)
            throw std::runtime_error("TLS handshake invalidated, un-secure connections are not accepted");

        return API::HookResult::Ok;
    }

    API::HookResultType onConnectionRead(const API::Connection &conn, tcp::socket &sock, std::vector<char> &buf, size_t &read) override
    {
        boost::system::error_code error;
        read = _socket->read_some(boost::asio::buffer(buf, buf.size()), error);

        return API::HookResult::Ok;
    }

    API::HookResultType onConnectionWrite(const API::Connection &conn, tcp::socket &sock, const std::vector<char> &buf, size_t &written) override
    {
        boost::system::error_code error;
        written = boost::asio::write(*_socket, boost::asio::buffer(buf), boost::asio::transfer_all(), error);
        return API::HookResult::Ok;
    }

  private:
    API::Request _req;
    API::Response _res;
    std::shared_ptr<boost::asio::ssl::context> _context;
    std::unique_ptr<tls_socket> _socket;
};

} // namespace Modules

} // namespace Zia