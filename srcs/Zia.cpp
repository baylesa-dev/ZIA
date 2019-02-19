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
    if (*_run == true) {
        std::cout << "A server is running !" << std::endl;
        _server->join();
    }
}

void Zia::Zia::startServer()
{
    bool *test = _run;
    if (*_run == true) {
        std::cout << "A server is already running !" << std::endl;
        return;
    }
    *_run = true;
    _server = new std::thread([test]() {
        Server *server = new Server();
        while (1) {
            if (*test == false) {
                std::cout << "[Server] Stop thread !" << std::endl;
                delete server;
                return (0);
            }
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