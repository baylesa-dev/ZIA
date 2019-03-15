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
#include "StaticRequestHandler.hpp"

namespace Zia
{
namespace Modules
{

class StaticModule : public API::Module
{
public:

    const std::string& getName() const override
    {
        return _name;
    }

    API::RequestHandler::pointer newRequestHandler() override
    {
        return std::make_shared<StaticRequestHandler>();
    }

    void onActivate(const API::ServerConfig& cfg) override
    {
    }
    void onDeactivate()
    {
    }
    void onConfigChange(const API::ServerConfig& cfg) override
    {
    }

private:
    std::string _name = "Static";
};

}
} // namespace Zia