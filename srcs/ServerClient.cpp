/*
** EPITECH PROJECT, 2019
** Zia
** File description:
** ServerClient cpp
*/

#include "ServerClient.hpp"

Zia::ServerClient::ServerClient(boost::asio::ip::tcp::socket socket,
        std::string ip,
        std::vector<std::shared_ptr<API::Module>> allModule)
        : _socket(std::move(socket))
{
        _connection.addr = ip;
        _connection.port = DEBUG_PORT;
}

Zia::ServerClient::~ServerClient()
{
        _socket.close();
}

void Zia::ServerClient::start()
{
}
