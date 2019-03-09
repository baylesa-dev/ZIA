/*
** EPITECH PROJECT, 2019
** Zia
** File description:
** ServerClient cpp
*/

#include "ParseRequest.hpp"
#include "ServerClient.hpp"

Zia::ServerClient::ServerClient(boost::asio::ip::tcp::socket socket,
    std::string ip,
    unsigned short port,
    std::shared_ptr<RequestsHandler> requestsHandler)
    : _socket(std::move(socket))
{
    _connection.addr = ip;
    _connection.port = port;
    _requestsHanler = requestsHandler;
}

Zia::ServerClient::~ServerClient()
{
    _socket.close();
}

void Zia::ServerClient::start()
{
    ParseRequest parse(_socket);
    // parsRequest lit le socket et ensuite remplie la struct reuqeste fait un getRequest pour l'avoir
    parse.parsRequest();
}
