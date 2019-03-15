/*
** EPITECH PROJECT, 2019
** Zia
** File description:
** ServerClient cpp
*/

#include "ParseRequest.hpp"
#include "ServerClient.hpp"
#include "AssemblesAnswer.hpp"
#include "string.h"

Zia::ServerClient::ServerClient(boost::asio::ip::tcp::socket socket,
    API::Connection connection,
    API::ServerConfig config,
    bool *run,
    std::shared_ptr<RequestsHandler> requestsHandler)
    : _socket(std::move(socket))
    , _connection(connection)
    , _config(config)
{
    _run = run;
    _requestsHanler = requestsHandler;
}

Zia::ServerClient::~ServerClient()
{
    _requestsHanler->onConnectionEnd(_connection, _socket);
    _socket.close();
}

void Zia::ServerClient::start()
{
    _requestsHanler->onConnectionStart(_connection, _socket);
    //_requestsHanler.onConnectionRead()
    read();
}

void Zia::ServerClient::read()
{
    auto self(std::enable_shared_from_this<ServerClient>::
    shared_from_this());
    _socket.async_read_some(boost::asio::buffer(_buffer, 512),
        [this, self](boost::system::error_code err, int len)
    {
        if (!err) {
            ParseRequest parse;
            parse.parsRequest(_buffer);
            _request = parse.getRequest();
            _requestsHanler->onBeforeRequest(_connection, _request);
            _requestsHanler->onRequest(_connection, _request, _response);
            //_requestsHanler->onRequestError(_connection, _statue, _response);
            _requestsHanler->onResponse(_connection, _response);
            strcpy(_buffer, AssemblesAnswer().run(_response).c_str());
            send();
        }
        if (*_run == true)
            read();
    });
}

void Zia::ServerClient::send()
{
    //_requestsHanler->onConnectionWrite();
    auto self(std::enable_shared_from_this<ServerClient>::
        shared_from_this());
    boost::asio::async_write(_socket,
        boost::asio::buffer(_buffer),
        [this, self](boost::system::error_code err, int len) {});
}
