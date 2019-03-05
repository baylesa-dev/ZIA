/*
** EPITECH PROJECT, 2019
** Zia
** File description:
** ServerClient
*/

#pragma once

#define DEBUG_PORT 4242
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <memory>
#include <iostream>
#include <vector>
#include "API.hpp"

namespace Zia
{

class ServerClient
{
public:
        ServerClient(boost::asio::ip::tcp::socket socket,
                std::string ip,
                std::vector<std::shared_ptr<API::Module>> allModule);
        ~ServerClient();
        void start();
protected:
private:
        API::Connection _connection;
        boost::asio::ip::tcp::socket _socket;
        std::vector<std::shared_ptr<API::Module>> _allModule;
};
} // namespace Zia
