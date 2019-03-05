#include <thread>
#include <iostream>
#include <vector>

#include "Cmd.hpp"
#include "Server.hpp"
#include "Zia.hpp"

Zia::Zia::Zia()
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

void Zia::Zia::startServer()
{
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
    //Debug change for ->join() when fix
    _server->detach();
    delete _server;
}

bool Zia::Zia::getRun()
{
    return *_run;
}
