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
#include "Zia/API.hpp"

using boost::asio::ip::tcp;

namespace Zia
{
namespace Modules
{

class StaticRequestHandler : public API::RequestHandler
{
  public:
    API::HookResultType onConnectionStart(const API::Connection &conn, tcp::socket &sock) override
    {
        return API::HookResult::Declined;
    }

    API::HookResultType onConnectionEnd(const API::Connection &conn, tcp::socket &sock) override
    {
        return API::HookResult::Declined;
    }

    API::HookResultType onConnectionRead(const API::Connection &conn, tcp::socket &sock, std::vector<char> &buf, size_t &read) override
    {
        return API::HookResult::Declined;
    }

    API::HookResultType onConnectionWrite(const API::Connection &conn, tcp::socket &sock, const std::vector<char> &buf, size_t &written) override
    {
        return API::HookResult::Declined;
    }

    API::HookResultType onBeforeRequest(const API::Connection &conn, API::Request &req) override
    {
        return API::HookResult::Declined;
    }

    API::HookResultType onRequest(const API::Connection &conn, const API::Request &req, API::Response &res) override
    {
        return API::HookResult::Declined;
    }

    API::HookResultType onRequestError(const API::Connection &conn, int status, API::Response &res) override
    {
        return API::HookResult::Declined;
    }

    API::HookResultType onResponse(const API::Connection &conn, API::Response &res) override
    {
        return API::HookResult::Declined;
    }

  private:
    API::Request _req;
    API::Response _res;
};

} // namespace Modules

} // namespace Zia