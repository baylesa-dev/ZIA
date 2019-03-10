/*
** EPITECH PROJECT, 2019
** Zia
** File description:
** main
*/

#include <iostream>
#include "Zia.hpp"
#include "ArgsParser.hpp"

int main(int ac, char **av)
{
    Zia::ArgsParser *arg = new Zia::ArgsParser(ac, av);
    Zia::Zia zia(arg);

    zia.runCli();
}
