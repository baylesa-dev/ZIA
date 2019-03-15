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
        std::cout << "conn.addr = " << conn.addr << "\nconn.port = " << conn.port <<  std::endl;
        return API::HookResult::Declined;
    }

    API::HookResultType onConnectionEnd(const API::Connection &conn, tcp::socket &sock) override
    {
        std::cout << "DEBUG onConnectionEnd() !" << std::endl;
        std::cout << "conn.addr = " << conn.addr << "\nconn.port = " << conn.port <<  std::endl;
        return API::HookResult::Declined;
    }

    API::HookResultType onConnectionRead(const API::Connection &conn, tcp::socket &sock, std::vector<char> &buf, size_t &read) override
    {
        std::cout << "DEBUG onConnectionRead() !" << std::endl;
        std::cout << "conn.addr = " << conn.addr << "\nconn.port = " << conn.port <<  std::endl;
        std::cout << "buf = ";
        for (auto c: buf)
            std::cout << c;
        std::cout << "\nread = " << read <<  std::endl;
        return API::HookResult::Declined;
    }

    API::HookResultType onConnectionWrite(const API::Connection &conn, tcp::socket &sock, const std::vector<char> &buf, size_t &written) override
    {
        std::cout << "DEBUG onConnectionWrite() !" << std::endl;
        std::cout << "conn.addr = " << conn.addr << "\nconn.port = " << conn.port <<  std::endl;
        std::cout << "buf = " << std::endl;
        for (auto c: buf)
            std::cout << c;
        std::cout << "\nwritten = " << written <<  std::endl;
        return API::HookResult::Declined;
    }

    API::HookResultType onBeforeRequest(const API::Connection &conn, API::Request &req) override
    {
        std::cout << "DEBUG onBeforeRequest() !" << std::endl;
        std::cout << "conn.addr = " << conn.addr << "\nconn.port = " << conn.port <<  std::endl;

        std::cout << "req.method = " << req.method <<  std::endl;
        std::cout << "req.uri = " << req.uri <<  std::endl;
        std::cout << "req.protocol = " << req.protocol <<  std::endl;
        std::cout << "req.headers" << std::endl;
        for (auto headers : req.headers)
            std::cout << headers.first << " : " << headers.second << std::endl;
        std::cout << "req.body = ";
        for (auto c: req.body)
            std::cout << c;
        std::cout << "\nreq.secure = " << req.secure <<  std::endl;

        return API::HookResult::Declined;
    }

    API::HookResultType onRequest(const API::Connection &conn, const API::Request &req, API::Response &res) override
    {
        std::cout << "DEBUG onRequest() !" << std::endl;
        std::cout << "conn.addr = " << conn.addr << "\nconn.port = " << conn.port <<  std::endl;

        std::cout << "req.method = " << req.method <<  std::endl;
        std::cout << "req.uri = " << req.uri <<  std::endl;
        std::cout << "req.protocol = " << req.protocol <<  std::endl;
        std::cout << "req.headers" << std::endl;
        for (auto headers : req.headers)
            std::cout << headers.first << " : " << headers.second << std::endl;
        std::cout << "req.body = ";
        for (auto c: req.body)
            std::cout << c;
        std::cout << "\nreq.secure = " << req.secure <<  std::endl;

        std::cout << "res.protocol = " << res.protocol <<  std::endl;
        std::cout << "res.status_code = " << res.status_code <<  std::endl;
        std::cout << "res.status_message = " << res.status_message <<  std::endl;
        std::cout << "res.headers" << std::endl;
        for (auto headers : res.headers)
            std::cout << headers.first << " : " << headers.second << std::endl;
        std::cout << "res.body = ";
        for (auto c: res.body)
            std::cout << c;
        std::cout << "\n" << std::endl;
        return API::HookResult::Declined;
    }

    API::HookResultType onRequestError(const API::Connection &conn, int status, API::Response &res) override
    {
        std::cout << "DEBUG onRequestError() !" << std::endl;
        std::cout << "conn.addr = " << conn.addr << "\nconn.port = " << conn.port <<  std::endl;

        std::cout << "status = " << status << std::endl;
        std::cout << "res.protocol = " << res.protocol <<  std::endl;
        std::cout << "res.status_code = " << res.status_code <<  std::endl;
        std::cout << "res.status_message = " << res.status_message <<  std::endl;
        std::cout << "res.headers" << std::endl;
        for (auto headers : res.headers)
            std::cout << headers.first << " : " << headers.second << std::endl;
        std::cout << "res.body = ";
        for (auto c: res.body)
            std::cout << c;
        std::cout << "\n" << std::endl;
        return API::HookResult::Declined;
    }

    API::HookResultType onResponse(const API::Connection &conn, API::Response &res) override
    {
        std::cout << "DEBUG onResponse() !" << std::endl;
        std::cout << "conn.addr = " << conn.addr << "\nconn.port = " << conn.port <<  std::endl;

        std::cout << "res.protocol = " << res.protocol <<  std::endl;
        std::cout << "res.status_code = " << res.status_code <<  std::endl;
        std::cout << "res.status_message = " << res.status_message <<  std::endl;
        std::cout << "res.headers" << std::endl;
        for (auto headers : res.headers)
            std::cout << headers.first << " : " << headers.second << std::endl;
        std::cout << "res.body = ";
        for (auto c: res.body)
            std::cout << c;
        std::cout << "\n" << std::endl;
        return API::HookResult::Declined;
    }

  private:
    API::Request _req;
    API::Response _res;
};

} // namespace Modules

} // namespace Zia