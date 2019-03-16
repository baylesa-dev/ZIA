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
#include "SSLRequestHandler.hpp"

namespace Zia
{
namespace Modules
{

class SSLModule : public API::Module
{
public:

    const std::string& getName() const override
    {
        return _name;
    }

    API::RequestHandler::pointer newRequestHandler() override
    {
        return std::make_shared<SSLRequestHandler>();
    }

    void onActivate(const API::ServerConfig& cfg) override
    {
        std::cout << "SSL onActivate() !" << std::endl;
    }
    void onDeactivate()
    {
        std::cout << "SSL onDeactivate() !" << std::endl;
    }
    void onConfigChange(const API::ServerConfig& cfg) override
    {
        std::cout << "SSL onConfigChange() !" << std::endl;
    }

private:
    std::string _name = "DEBUG";
};

}
} // namespace Zia