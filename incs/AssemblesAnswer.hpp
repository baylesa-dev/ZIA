/*
** EPITECH PROJECT, 2019
** ZIa
** File description:
** AssemblesAnswer
*/

#pragma once

#include "API.hpp"

namespace Zia
{

class AssemblesAnswer
{
  public:
    AssemblesAnswer();
    ~AssemblesAnswer();
    std::string run(API::Response &req);

  protected:
  private:
};

} // namespace Zia