/*
** EPITECH PROJECT, 2019
** Zia
** File description:
** Server cpp
*/

#include "Server.hpp"
#include "ServerClient.hpp"

boost::asio::io_service io_service_g;

Zia::Server::Server()
        : _acceptor(io_service_g, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), DEBUG_PORT))
        , _socket(io_service_g)
{
        std::cout << "New Server !" << std::endl;
        start();
}

Zia::Server::~Server()
{
        _socket.close();
}

void Zia::Server::stop()
{
    std::cout << "Oui" << std::endl;
        io_service_g.stop();
}

void Zia::Server::start()
{
    //loadModules();
    accept();
    io_service_g.run();
}

void Zia::Server::accept()
	{
		_acceptor.async_accept(_socket,
			[this](boost::system::error_code err)
		{
			if (!err) {
				std::string ip(_socket.remote_endpoint()
					.address().to_string());
				std::make_shared<ServerClient>(
					std::move(_socket), ip,
					this->_allModule)->start();
                                std::cout << "New Connection !    IP : " << ip <<std::endl;
			}
			accept();
		});
	}
