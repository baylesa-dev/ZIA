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

#define DEFAULT_PORT 4242
#define CONFIG_PATH "config.xml"

namespace Zia
{

class Zia
{
  public:
    Zia();
    ~Zia();
    void runCli();
    static unsigned short getPort();
    void startServer();
    void stopServer();
    void forceStopServer();
    bool getRun();

  protected:
  private:
    std::thread *_server;
    bool *_run;
};

} // namespace Zia
