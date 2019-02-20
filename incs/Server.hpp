/*
** EPITECH PROJECT, 2019
** Zia
** File description:
** Server
*/

#pragma once

#include <memory>
#include <vector>
#include "API.hpp"

namespace Zia
{

class Server
{
  public:
    Server();
    ~Server();

  protected:
  private:
    std::vector<std::shared_ptr<API::Module>> _allModule;
};

} // namespace Zia