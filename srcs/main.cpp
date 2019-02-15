#include <iostream>
#include "Zia.hpp"

// DEBUG
#include <unistd.h>
//

int main(int ac, char **av)
{
    Zia::Zia *a = new Zia::Zia();
    a->startServer();
    sleep(1);
    a->stopServer();
}