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

namespace Zia {
namespace Modules {

class PHPRequestHandler : public API::RequestHandler
{
public:
    API::HookResultType onConnectionStart(const API::Connection& conn, tcp::socket& sock) override
    {
        return API::HookResult::Declined;
    }

    API::HookResultType onRequest(const API::Connection& conn, const API::Request& req, API::Response& res) override
    {
        _req = req;
        return API::HookResult::Declined;
    }

    API::HookResultType onResponse(const API::Connection& conn, API::Response& res) override
    {
        _res = res;
        return API::HookResult::Declined;
    }

    API::HookResultType onConnectionEnd(const API::Connection& conn, tcp::socket& sock) override
    {
        return API::HookResult::Declined;
    }

private:
    API::Request _req;
    API::Response _res;
};

}

}