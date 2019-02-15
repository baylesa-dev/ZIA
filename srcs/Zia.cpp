#include <thread>
#include <iostream>

#include "Server.hpp"
#include "Zia.hpp"

Zia::Zia::Zia()
{
    _run = (bool *)malloc(sizeof(bool));
}

Zia::Zia::~Zia()
{
    if (*_run == true)
        _server->join();
}

void Zia::Zia::startServer()
{
    if (*_run == true) {
        std::cout << "A server is already running !" << std::endl;
        return;
    }
    bool *test = _run;

    *_run = true;
    _server = new std::thread([test]() {
        Server *server = new Server();
        while (1) {
            if (*test == false) {
                std::cout << "Stop thread !" << std::endl;
                delete server;
                return (0);
            }
            server->close();
        }
    });
}

void Zia::Zia::forceStopServer()
{
    std::cout << "Force stop server !" << std::endl;
    _server->detach();
    *_run = false;
}

void Zia::Zia::stopServer()
{
    std::cout << "Stop server !" << std::endl;
    *_run = false;
}