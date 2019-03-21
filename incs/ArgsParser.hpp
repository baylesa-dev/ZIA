/*
** EPITECH PROJECT, 2019
** Zia
** File description:
** ArgsParser
*/

#pragma once

#include <string>
#include <vector>

namespace Zia
{

class ArgsParser
{
  public:
    ArgsParser(int argc, char **argv);
    ~ArgsParser();
    std::string &getConfigPath();
    std::string &getModulesPath();

  protected:
  private:
    std::vector<std::string> _argv;
    std::string _configPath;
    std::string _modulesPath;
    std::string _getNextArg(int i);
};

}
