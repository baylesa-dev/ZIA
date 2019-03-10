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

class DEBUGRequestHandler : public API::RequestHandler
{
  public:
    API::HookResultType onConnectionStart(const API::Connection &conn, tcp::socket &sock) override
    {
        std::cout << "DEBUG onConnectionStart() !" << std::endl;
        return API::HookResult::Declined;
    }

    API::HookResultType onConnectionEnd(const API::Connection &conn, tcp::socket &sock) override
    {
        std::cout << "DEBUG onConnectionEnd() !" << std::endl;
        return API::HookResult::Declined;
    }

    API::HookResultType onConnectionRead(const API::Connection &conn, tcp::socket &sock, std::vector<char> &buf, size_t &read) override
    {
        std::cout << "DEBUG onConnectionRead() !" << std::endl;
        return API::HookResult::Declined;
    }

    API::HookResultType onConnectionWrite(const API::Connection &conn, tcp::socket &sock, const std::vector<char> &buf, size_t &written) override
    {
        std::cout << "DEBUG onConnectionWrite() !" << std::endl;
        return API::HookResult::Declined;
    }

    API::HookResultType onBeforeRequest(const API::Connection &conn, API::Request &req) override
    {
        std::cout << "DEBUG onBeforeRequest() !" << std::endl;
        return API::HookResult::Declined;
    }

    API::HookResultType onRequest(const API::Connection &conn, const API::Request &req, API::Response &res) override
    {
        std::cout << "DEBUG onRequest() !" << std::endl;
        return API::HookResult::Declined;
    }

    API::HookResultType onRequestError(const API::Connection &conn, int status, API::Response &res) override
    {
        std::cout << "DEBUG onRequestError() !" << std::endl;
        return API::HookResult::Declined;
    }

    API::HookResultType onResponse(const API::Connection &conn, API::Response &res) override
    {
        std::cout << "DEBUG onResponse() !" << std::endl;
        return API::HookResult::Declined;
    }

  private:
    API::Request _req;
    API::Response _res;
};

} // namespace Modules

} // namespace Zia