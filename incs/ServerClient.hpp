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

class ServerClient : public std::enable_shared_from_this<ServerClient>
{
public:
    ServerClient(boost::asio::ip::tcp::socket socket,
                API::Connection connection,
                API::ServerConfig config,
                bool *run,
                std::shared_ptr<RequestsHandler> requestsHandler);
    ~ServerClient();
    void start();
    void read();
    void send();

protected:
private:
    bool *_run;
    API::Connection _connection;
    boost::asio::ip::tcp::socket _socket;
    std::shared_ptr<RequestsHandler> _requestsHanler;
    API::ServerConfig _config;
	char _buffer[512];
    API::Request _request;
    API::Response _response;
};
} // namespace Zia
