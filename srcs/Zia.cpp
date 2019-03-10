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

Zia::Zia::Zia(ArgsParser *arg)
    : _args(arg)
{
    _run = (bool *)malloc(sizeof(bool));
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

unsigned short Zia::Zia::getPort(std::string configPath)
{
    unsigned short port;
    pugi::xml_document config;
    pugi::xml_parse_result result = config.load_file(configPath.c_str());
    port = (unsigned short) config.child("server").attribute("port").as_int();
    if (port == 0)
        port = DEFAULT_PORT;
    return (port);
}

void Zia::Zia::startServer()
{
    bool *run = _run;
    ArgsParser *tmp = _args;

    if (*_run == true) {
        std::cout << "A server is already running !" << std::endl;
        return;
    }
    *_run = true;
    _server = new std::thread([run, tmp]() {
        std::shared_ptr<Server> serverPtr =
            std::shared_ptr<Server>(new Server(run,
                Zia::Zia::getPort(tmp->getConfigPath()), tmp));
        serverPtr->start();
    });
}

void Zia::Zia::forceStopServer()
{
    if (_server != NULL)
        _server->detach();
    *_run = false;
}

void Zia::Zia::stopServer()
{
    *_run = false;
    _server->join();
    delete _server;
}

bool Zia::Zia::getRun()
{
    return *_run;
}
