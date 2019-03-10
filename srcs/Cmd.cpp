/*
** EPITECH PROJECT, 2019
** Zia
** File description:
** Cmd
*/

#include <string>
#include <iostream>

#include "Cmd.hpp"
#include "Zia.hpp"

Zia::Cmd::Cmd(Zia *zia)
    : _zia(zia)
{
}

Zia::Cmd::~Cmd()
{
}

void Zia::Cmd::runCmd(std::string str)
{
    this->_parceCmd(str);
    this->_stop();
    this->_reload();
    this->_status();
    this->_help();
    _cmd.clear();
}

void Zia::Cmd::_parceCmd(std::string str)
{
    while (str.find(' ') != std::string::npos) {
        _cmd.push_back(str.substr(0, str.find(' ')));
        str.erase(0, str.find(' ')+ 1);
    }
    if (str.size() != 0)
        _cmd.push_back(str);
}

void Zia::Cmd::_stop()
{
    if (_cmd.at(0) == "stop") {
        std::cout << "Make a connection for Stop" << std::endl;
        if (_cmd.size() == 2) {
            if (_cmd.at(1) == "-f" || _cmd.at(1) == "--force")
                _zia->forceStopServer();
        }
        else
            _zia->stopServer();
        std::cout << "Stop server !" << std::endl;
        exit(0);
    }
}

void Zia::Cmd::_reload()
{
    if (_cmd.at(0) == "reload") {
        std::cout << "Make a connection for Reload" << std::endl;
        _zia->stopServer();
        _zia->startServer();
        std::cout << "Reload server !" << std::endl;
    }
}

void Zia::Cmd::_status()
{
    if (_cmd.at(0) == "status") {
        if (_zia->getRun())
            std::cout << "A server is running !" << std::endl;
        else
            std::cout << "No server is running !" << std::endl;
    }
}

void Zia::Cmd::_help()
{
    if (_cmd.at(0) == "help") {
        std::cout << "usage:" << std::endl
            << "\tstop [-f | --force]" << std::endl
            << "\treload" << std::endl
            << "\tstatus" << std::endl;
    }
}
