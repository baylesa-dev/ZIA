/*
** EPITECH PROJECT, 2019
** Zia
** File description:
** Zia cpp
*/

#include <thread>
#include <iostream>
#include <fstream>
#include <vector>

#include "Cmd.hpp"
#include "Server.hpp"
#include "Zia.hpp"

Zia::Zia::Zia()
{
    _run = (bool *)malloc(sizeof(bool));
    setConfig();
    printStartMessage();
}

Zia::Zia::~Zia()
{
    if (*_run == true) {
        std::cout << "A server is running !" << std::endl;
        _server->join();
    }
    free(_run);
}

void Zia::Zia::runCli()
{
    std::string str;
    Cmd cmd(this);

    this->startServer();
    while (1) {
        std::getline(std::cin, str);
        cmd.runCmd(str);
    }
}

void Zia::Zia::setConfig()
{
        pugi::xml_document config;

        switch(PLATFORM)
        {
                case 0  : _config.platform = API::ServerConfig::Platform::Linux;        break;
                case 1  : _config.platform = API::ServerConfig::Platform::Windows;      break;
                case 2  : _config.platform = API::ServerConfig::Platform::Macos;        break;
        }
        pugi::xml_parse_result result = config.load_file("config.xml");
        if (!result) {
                std::cout << "config.xml: "<< result.description() << std::endl;
                _config.name = "Default Zia";
                _config.version = "0.0.0";
                return ;
        }
        _config.name = config.child("server").attribute("name").value();
        _config.version = config.child("server").attribute("version").value();
}

void Zia::Zia::printStartMessage()
{
        std::cout << "Server name : " << _config.name << std::endl;
        std::cout << "Server Version :" << _config.version << std::endl << std::endl;
        std::cout << " _______   _ " << std::endl;
        std::cout << "|_  /_ _| /_\\"  << std::endl;
        std::cout << " / / | | / _ \\"  << std::endl;
        std::cout << "/___|___/_/ \\_\\" << std::endl << std::endl;
}

void Zia::Zia::startServer()
{
    bool *run = _run;

    if (*_run == true) {
        std::cout << "A server is already running !" << std::endl;
        return;
    }
    *_run = true;
    _server = new std::thread([]() {
        std::shared_ptr<Server> serverPtr = std::shared_ptr<Server>(new Server);
    });
}

void Zia::Zia::forceStopServer()
{
    std::cout << "Force stop server !" << std::endl;
    if (_server != NULL)
        _server->detach();
    *_run = false;
}

void Zia::Zia::stopServer()
{
    std::cout << "Stop server !" << std::endl;
    *_run = false;
    // TODO change detach for join
    _server->detach();
    delete _server;
}

bool Zia::Zia::getRun()
{
    return *_run;
}
