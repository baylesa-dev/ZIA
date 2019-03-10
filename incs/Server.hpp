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
#include "LoadModules.hpp"

#define VERSION "1.0.0"
#define CONFIG_PATH "config.xml"
#define MODULE_PATH "modules/"

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
    Server(unsigned short port);
    ~Server();
    void setConfig();
    void setDefaultConfig();
    void setModulesPath();
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
    std::vector<std::string> _allModulesPath;
    LoadModules _moduleLoader;
    boost::asio::ip::tcp::socket _socket;
    boost::asio::ip::tcp::acceptor _acceptor;
};

} // namespace Zia
