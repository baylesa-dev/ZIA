/*
** EPITECH PROJECT, 2019
** zia
** File description:
** zia
*/

#pragma once

#include <iostream>
#include <string>
#include "Zia/API.hpp"
#include "DEBUGRequestHandler.hpp"

namespace Zia
{
namespace Modules
{

class DEBUGModule : public API::Module
{
public:

    const std::string& getName() const override
    {
        return _name;
    }

    API::RequestHandler::pointer newRequestHandler() override
    {
        return std::make_shared<DEBUGRequestHandler>();
    }

    void onActivate(const API::ServerConfig& cfg) override
    {
        std::cout << "DEBUG onActivate() !" << std::endl;
    }
    void onDeactivate()
    {
        std::cout << "DEBUG onDeactivate() !" << std::endl;
    }
    void onConfigChange(const API::ServerConfig& cfg) override
    {
        std::cout << "DEBUG onConfigChange() !" << std::endl;
    }

private:
    std::string _name = "DEBUG";
};

}
} // namespace Zia