/*
** EPITECH PROJECT, 2019
** Zia
** File description:
** ParseRequest
*/

#pragma once

#include <string>
#include <vector>
#include "API.hpp"

namespace Zia
{

class ParseRequest
{
  public:
    ParseRequest();
    ~ParseRequest();
    API::Request& getRequest();
    void parsRequest(std::vector<char> &buffer);

  protected:
  private:
    API::Request _request;
    std::string _bufferToString(std::vector<char> &buffer);
    void _getMethod(std::string &req);
    void _getUri(std::string &req);
    void _getProtocol(std::string &req);
    void _getHeaders(std::string &req);
    void _getBody(std::string &req);
};

} // namespace Zia
