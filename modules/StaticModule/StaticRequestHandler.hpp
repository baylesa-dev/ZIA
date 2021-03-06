/*
** EPITECH PROJECT, 2019
** CPP_zia_2018
** File description:
** [log module] Request handler definition
*/

#pragma once

#include <iostream>
#include <chrono>
#include <boost/asio.hpp>
#include <fstream>

#include "Zia/API.hpp"

#define NOT_FOUND "<!DOCTYPE html><html><head><meta charset=\"utf-8\">\
    <title>Error 404</title></head><body><p>404 Not Found</p></body></html>\0"

using boost::asio::ip::tcp;

namespace Zia
{
namespace Modules
{

class StaticRequestHandler : public API::RequestHandler
{
  public:
    StaticRequestHandler(std::string basePath = "/usr/www")
        : _basePath(basePath)
    {
    }

    API::HookResultType onRequest(const API::Connection &conn, const API::Request &req, API::Response &res) override
    {
        _path = _basePath + req.uri;
        if (!access(_path.c_str(), R_OK))
        {
            res.protocol = "HTTP/1.1";
            res.status_code = 200;
            res.status_message = "OK";
            std::ifstream inFile;
            inFile.open(_path);
            std::stringstream strStream;
            strStream << inFile.rdbuf();
            std::string str = strStream.str();
            for (auto c: str)
                res.body.push_back(c);
            return API::HookResult::Ok;
        }
        res.protocol = "HTTP/1.1";
        res.status_code = 404;
        res.status_message = "Not Found";
        std::string str(NOT_FOUND);
        for (auto c: str)
            res.body.push_back(c);
        return API::HookResult::Declined;
    }

  private:
    API::Request _req;
    API::Response _res;
    std::string _basePath;
    std::string _path;
};

} // namespace Modules

} // namespace Zia