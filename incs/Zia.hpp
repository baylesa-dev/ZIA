/*
** EPITECH PROJECT, 2019
** Zia
** File description:
** Zia
*/

#pragma once

#include <thread>

namespace Zia
{

class Zia
{
  public:
    Zia();
    ~Zia();
    void startServer();
    void stopServer();
    void forceStopServer();

  protected:
  private:
    std::thread *_server;
    bool *_run;
};

} // namespace Zia