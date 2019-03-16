/*
** EPITECH PROJECT, 2019
** Zia
** File description:
** RequestHandler cpp
*/

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
        if ((*it)->onConnectionStart(conn, sock))
            break;
    }
}

void Zia::RequestsHandler::onConnectionEnd(const API::Connection& conn,
    boost::asio::ip::tcp::socket& sock)
{
    for(auto it = _requestsHanler.begin(); it != _requestsHanler.end(); it++) {
        if ((*it)->onConnectionEnd(conn, sock))
            break;
    }
}

void Zia::RequestsHandler::onConnectionRead(const API::Connection& conn,
    boost::asio::ip::tcp::socket& sock,
    std::vector<char>& buf,
    size_t& read)
{
    for(auto it = _requestsHanler.begin(); it != _requestsHanler.end(); it++) {
        if ((*it)->onConnectionRead(conn, sock, buf, read))
            break;
    }
}

void Zia::RequestsHandler::onConnectionWrite(const API::Connection& conn,
    boost::asio::ip::tcp::socket& sock,
    const std::vector<char>& buf,
    size_t& written)
{
    for(auto it = _requestsHanler.begin(); it != _requestsHanler.end(); it++) {
        if ((*it)->onConnectionWrite(conn, sock, buf, written))
            break;
    }
}

void Zia::RequestsHandler::onBeforeRequest(const API::Connection& conn, API::Request& req)
{
    for(auto it = _requestsHanler.begin(); it != _requestsHanler.end(); it++) {
        if ((*it)->onBeforeRequest(conn, req))
            break;
    }
}

void Zia::RequestsHandler::onRequest(const API::Connection& conn, const API::Request& req, API::Response& res)
{
    for(auto it = _requestsHanler.begin(); it != _requestsHanler.end(); it++) {
        if ((*it)->onRequest(conn, req, res))
            return ;
    }
    res.protocol = "HTTP/1.1";
    res.status_code = 204;
    res.status_message = "No Content";
}

void Zia::RequestsHandler::onRequestError(const API::Connection& conn, int status, API::Response& res)
{
    for(auto it = _requestsHanler.begin(); it != _requestsHanler.end(); it++) {
        if ((*it)->onRequestError(conn, status, res))
            break;
    }
}

void Zia::RequestsHandler::onResponse(const API::Connection& conn, API::Response& res)
{
    for(auto it = _requestsHanler.begin(); it != _requestsHanler.end(); it++) {
        if ((*it)->onResponse(conn, res))
            break;
    }
}
