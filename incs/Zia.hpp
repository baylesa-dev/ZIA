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

namespace Zia
{

class Zia
{
  public:
    Zia();
    ~Zia();
    void runCli();
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
