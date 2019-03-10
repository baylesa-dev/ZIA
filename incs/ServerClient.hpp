/*
** EPITECH PROJECT, 2019
** Zia
** File description:
** ServerClient
*/

#pragma once

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <memory>
#include <iostream>
#include <vector>
#include "RequestsHandler.hpp"
#include "API.hpp"

namespace Zia
{

class ServerClient
{
public:
    ServerClient(boost::asio::ip::tcp::socket socket,
                API::Connection connection,
                API::ServerConfig config,
                std::shared_ptr<RequestsHandler> requestsHandler);
    ~ServerClient();
    void start();
protected:
private:
    API::Connection _connection;
    boost::asio::ip::tcp::socket _socket;
    std::shared_ptr<RequestsHandler> _requestsHanler;
    API::ServerConfig _config;
};
} // namespace Zia
