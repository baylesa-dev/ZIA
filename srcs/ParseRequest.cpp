/*
** EPITECH PROJECT, 2019
** ZIa
** File description:
** ParseRequest
*/

#include <iostream>

#include "ParseRequest.hpp"

Zia::ParseRequest::ParseRequest(boost::asio::ip::tcp::socket &socket)
    : _socket(std::move(socket))
{
}

Zia::ParseRequest::~ParseRequest()
{
}

Zia::API::Request &Zia::ParseRequest::getRequest()
{
    return _request;
}

void Zia::ParseRequest::parsRequest()
{
    boost::asio::streambuf buffer;
    boost::system::error_code ec;

    boost::asio::read(_socket, buffer, ec);
    if (!ec) {
        std::cerr << ec << std::endl;
        return;
    }
    std::string req = _bufferToString(buffer);
    _getMethod(req);
    _getUri(req);
    _getProtocol(req);
    _getHeaders(req);
    _getBody(req);
}

std::string Zia::ParseRequest::_bufferToString(const boost::asio::streambuf &buffer)
{
  using boost::asio::buffers_begin;

  auto bufs = buffer.data();
  std::string result(buffers_begin(bufs), buffers_begin(bufs) + buffer.size());
  return result;
}

void Zia::ParseRequest::_getMethod(std::string &req)
{
    _request.method = req.substr(0, req.find(' '));
    req.erase(0, req.find(' ') + 1);
}

void Zia::ParseRequest::_getUri(std::string &req)
{
    _request.uri = req.substr(0, req.find(' '));
    req.erase(0, req.find(' ') + 1);
}

void Zia::ParseRequest::_getProtocol(std::string &req)
{
    _request.protocol = req.substr(0, req.find('\r'));
    req.erase(0, req.find('\r') + 2);
}

void Zia::ParseRequest::_getHeaders(std::string &req)
{
    std::string tmp1;
    std::string tmp2;

    while (req.find('\r') != 0) {
        tmp1 = req.substr(0, req.find(": "));
        req.erase(0, req.find(": ") + 2);
        tmp2 = req.substr(0, req.find('\n') - 1);
        req.erase(0, req.find('\r') + 2);
        std::pair<std::string,std::string> obj(tmp1, tmp2);
        _request.headers.insert(obj);
    }
    req.erase(0, req.find('\r') + 2);
}

void Zia::ParseRequest::_getBody(std::string &req)
{
    for (int i = 0; i != req.size(); i++) {
        _request.body.push_back(req.at(i));
    }
}