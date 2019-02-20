/*
** EPITECH PROJECT, 2019
** Zia
** File description:
** Cmd
*/

#pragma once

#include <vector>
#include <string>

#include "Zia.hpp"

namespace Zia {

class Cmd {
    public:
        Cmd(Zia *zia);
        ~Cmd();
        void runCmd(std::string);

    protected:
    private:
        Zia *_zia;
        std::vector<std::string> _cmd;
        void _parceCmd(std::string);
        void _stop();
        void _reload();
        void _status();
        void _help();
};

}