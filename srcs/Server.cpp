#include <iostream>
#include "Server.hpp"


Zia::Server::Server()
{
    std::cout << "Server class start" << std::endl;
}

Zia::Server::~Server()
{
    std::cout << "Server class kill" << std::endl;
}

void Zia::Server::close()
{
    std::cout << "Server run" << std::endl;
}
void Zia::Server::getModule()
{
}
int Zia::Server::getStatus()
{
}