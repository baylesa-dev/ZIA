/*
** EPITECH PROJECT, 2019
** Zia
** File description:
** Zia
*/

#pragma once

#include <thread>
#include <vector>
#include <memory>
#include "Server.hpp"
#include "API.hpp"
#include "pugixml.hpp"
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

class Zia
{
  public:
    Zia();
    ~Zia();
    void setConfig();
    void printStartMessage();
    void runCli();
    void startServer();
    void stopServer();
    void forceStopServer();
    bool getRun();

  protected:
  private:
    std::thread *_server;
    bool *_run;
    API::ServerConfig _config;
};

} // namespace Zia
