/*
** EPITECH PROJECT, 2019
** Zia
** File description:
** Server
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

class Server
{
  public:
    Server();
    ~Server();
    void stop();
    void start();
    void accept();

  protected:
  private:
    std::vector<std::shared_ptr<API::Module>> _allModule;
    boost::asio::ip::tcp::socket _socket;
    boost::asio::ip::tcp::acceptor _acceptor;
};

} // namespace Zia
