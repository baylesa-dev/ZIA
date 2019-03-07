/*
** EPITECH PROJECT, 2019
** zia
** File description:
** zia
*/

#pragma once

#include <iostream>
#include <string>
#include "API.hpp"
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

private:
    std::string _name = "PHP";
};

}
} // namespace Zia