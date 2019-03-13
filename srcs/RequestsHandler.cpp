/*
** EPITECH PROJECT, 2019
** Zia
** File description:
** RequestHandler cpp
*/

#include <iostream>

#include "RequestsHandler.hpp"

Zia::RequestsHandler::RequestsHandler(std::vector<API::Module::pointer> modules)
{
    for(auto it = modules.begin(); it != modules.end(); it++) {
        _requestsHanler.push_back((*it)->newRequestHandler());
    }
}

Zia::RequestsHandler::~RequestsHandler()
{

}

void Zia::RequestsHandler::onConnectionStart(const API::Connection& conn,
    boost::asio::ip::tcp::socket& sock)
{
    for(auto it = _requestsHanler.begin(); it != _requestsHanler.end(); it++) {
        (*it)->onConnectionStart(conn, sock);
    }
}

void Zia::RequestsHandler::onConnectionEnd(const API::Connection& conn,
    boost::asio::ip::tcp::socket& sock)
{
    for(auto it = _requestsHanler.begin(); it != _requestsHanler.end(); it++) {
        (*it)->onConnectionEnd(conn, sock);
    }
}

void Zia::RequestsHandler::onConnectionRead(const API::Connection& conn,
    boost::asio::ip::tcp::socket& sock,
    std::vector<char>& buf,
    size_t& read)
{
    for(auto it = _requestsHanler.begin(); it != _requestsHanler.end(); it++) {
        (*it)->onConnectionRead(conn, sock, buf, read);
    }
}

void Zia::RequestsHandler::onConnectionWrite(const API::Connection& conn,
    boost::asio::ip::tcp::socket& sock,
    const std::vector<char>& buf,
    size_t& written)
{
    for(auto it = _requestsHanler.begin(); it != _requestsHanler.end(); it++) {
        (*it)->onConnectionWrite(conn, sock, buf, written);
    }
}

void Zia::RequestsHandler::onBeforeRequest(const API::Connection& conn, API::Request& req)
{
    for(auto it = _requestsHanler.begin(); it != _requestsHanler.end(); it++) {
        (*it)->onBeforeRequest(conn, req);
    }
}

void Zia::RequestsHandler::onRequest(const API::Connection& conn, const API::Request& req, API::Response& res)
{
    for(auto it = _requestsHanler.begin(); it != _requestsHanler.end(); it++) {
        (*it)->onRequest(conn, req, res);
    }
}

void Zia::RequestsHandler::onRequestError(const API::Connection& conn, int status, API::Response& res)
{
    for(auto it = _requestsHanler.begin(); it != _requestsHanler.end(); it++) {
        (*it)->onRequestError(conn, status, res);
    }
}

void Zia::RequestsHandler::onResponse(const API::Connection& conn, API::Response& res)
{
    for(auto it = _requestsHanler.begin(); it != _requestsHanler.end(); it++) {
        (*it)->onResponse(conn, res);
    }
}
