/*
** EPITECH PROJECT, 2019
** Zia
** File description:
** Server
*/

#pragma once

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <memory>
#include <iostream>
#include <vector>
#include "API.hpp"
#include "pugixml.hpp"
#include "RequestsHandler.hpp"

#define DEFAULT_PORT 4242
#define VERSION "1.0.0"
#define CONFIGPATH "config.yml"

#ifdef __linux__
#       define PLATFORM 0
#elif _WIN32
#       define PLATFORM 1
#elif __APPLE__
#       define PLATFORM 2
#endif

namespace Zia
{

class Server
{
  public:
    Server();
    ~Server();
    void setConfig();
    void setDefaultConfig();
    void setPlatform();
    void printStartMessage();
    void stop();
    void start();
    void accept();

  protected:
  private:
    API::ServerConfig _config;
    unsigned short _port;
    std::shared_ptr<RequestsHandler> _requestsHanler;
    std::vector<API::Module::pointer> _allModule;
    boost::asio::ip::tcp::socket _socket;
    boost::asio::ip::tcp::acceptor _acceptor;
};

} // namespace Zia
