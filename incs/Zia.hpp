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
#include "ArgsParser.hpp"
#include "API.hpp"

#define DEFAULT_PORT 4242
#define CONFIG_PATH "config.xml"

namespace Zia
{

class Zia
{
  public:
    Zia(ArgsParser *arg);
    ~Zia();
    void runCli();
    static unsigned short getPort(std::string configPath);
    void startServer();
    void stopServer();
    void forceStopServer();
    bool getRun();

  protected:
  private:
    boost::asio::io_service _io_service;
    std::thread *_server;
    bool *_run;
    ArgsParser *_args;
};

} // namespace Zia
