/*
** EPITECH PROJECT, 2019
** Zia
** File description:
** RequestHandler hpp
*/

#pragma once

#include "API.hpp"
#include <memory>
#include <vector>
#include <boost/asio.hpp>

namespace Zia
{
    class RequestsHandler
    {
    public:
        RequestsHandler(std::vector<std::shared_ptr<API::Module>> modules);
        ~RequestsHandler();
        void onConnectionStart(const API::Connection& conn, boost::asio::ip::tcp::socket& sock);
        void onConnectionEnd(const API::Connection& conn, boost::asio::ip::tcp::socket& sock);
        void onConnectionRead(const API::Connection& conn, boost::asio::ip::tcp::socket& sock, std::vector<char>& buf, size_t& read);
        void onConnectionWrite(const API::Connection& conn, boost::asio::ip::tcp::socket& sock, const std::vector<char>& buf, size_t& written);
        void onBeforeRequest(const API::Connection& conn, API::Request& req);
        void onRequest(const API::Connection& conn, const API::Request& req, API::Response& res);
        void onRequestError(const API::Connection& conn, int status, API::Response& res);
        void onResponse(const API::Connection& conn, API::Response& res);

      protected:
      private:
        std::vector<API::RequestHandler::pointer> _requestsHanler;
    };
} // namespace Zia
