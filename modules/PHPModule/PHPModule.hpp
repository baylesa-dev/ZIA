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
#include "PHPRequestHandler.hpp"

namespace Zia
{
namespace Modules
{

class PHPModule : public API::Module
{
public:

    const std::string& getName() const override
    {
        return _name;
    }

    API::RequestHandler::pointer newRequestHandler() override
    {
        return std::make_shared<PHPRequestHandler>();
    }

    void onActivate(const API::ServerConfig& cfg) override
    {
        std::cout << "PHP module activate !" << std::endl;
    }
    void onDeactivate()
    {
        std::cout << "PHP module deactivate !" << std::endl;
    }

private:
    std::string _name = "PHP";
};

}
} // namespace Zia