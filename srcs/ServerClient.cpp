/*
** EPITECH PROJECT, 2019
** Zia
** File description:
** ServerClient cpp
*/

#include "ParseRequest.hpp"
#include "ServerClient.hpp"
#include "AssemblesAnswer.hpp"

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
            std::vector<char> tmp(_buffer, _buffer + len);
            _bufferRead = tmp;
            std::cout << _bufferRead.size() << std::endl;
            onRead();
            _bufferRead.clear();
        }
        if (*_run == true)
            read();
    });
}

void Zia::ServerClient::onRead()
{
    ParseRequest parse;
    parse.parsRequest(_bufferRead);
    _request = parse.getRequest();
    _requestsHanler->onBeforeRequest(_connection, _request);
    _requestsHanler->onRequest(_connection, _request, _response);
    if (_response.status_code >= 400)
        _requestsHanler->onRequestError(_connection, _response.status_code, _response);
    _requestsHanler->onResponse(_connection, _response);
    std::string tmp = AssemblesAnswer().run(_response).c_str();
    //_bufferWrite.clean();
    _bufferWrite = std::vector<char>(tmp.begin(), tmp.end());
    send();
}

void Zia::ServerClient::send()
{
    //_requestsHanler->onConnectionWrite();
    auto self(std::enable_shared_from_this<ServerClient>::
        shared_from_this());
    boost::asio::async_write(_socket,
        boost::asio::buffer(_bufferWrite),
        [this, self](boost::system::error_code err, int len) {});
}
