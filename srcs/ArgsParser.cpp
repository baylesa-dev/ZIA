/*
** EPITECH PROJECT, 2019
** Zia
** File description:
** ArgsParser
*/

#include <string>
#include <iostream>
#include "ArgsParser.hpp"

Zia::ArgsParser::ArgsParser(int argc, char **argv)
    : _modulesPath(std::string(".")), _configPath(std::string("./config.xml"))
{
    for (int i = 0; i != argc; i++)
       _argv.push_back(std::string(argv[i]));
    for (int i = 0; i != _argv.size(); i++) {
        if (_argv.at(i) == "--modules")
            _modulesPath = this->_getNextArg(i);
        if (_argv.at(i) == "--config")
            _configPath = this->_getNextArg(i);
    }
}

Zia::ArgsParser::~ArgsParser()
{
}

std::string &Zia::ArgsParser::getConfigPath()
{
    return _configPath;
}

std::string &Zia::ArgsParser::getModulesPath()
{
    return _modulesPath;
}

std::string Zia::ArgsParser::_getNextArg(int i)
{
    if (i + 1 <= _argv.size()) {
        return _argv.at(i + 1);
    }
    return std::string(".");
}
