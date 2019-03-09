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
        : _acceptor(io_service_g, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), DEFAULT_PORT))
        , _socket(io_service_g)
{
        std::cout << "New Server !" << std::endl;
        std::shared_ptr<RequestsHandler> _requestsHanler = std::shared_ptr<RequestsHandler>(new RequestsHandler(_allModule));
        setConfig();
        printStartMessage();
        start();
}

Zia::Server::~Server()
{
        _socket.close();
}

void Zia::Server::setConfig()
{
        pugi::xml_document config;
        pugi::xml_parse_result result = config.load_file("config.xml");
        if (!result) {
            std::cout << "config.xml: "<< result.description() << std::endl;
            setDefaultConfig();
            return;
        }
        _config.name = config.child("server").attribute("name").value();
        _config.version = config.child("server").attribute("version").value();
        _port = (unsigned short) config.child("server").attribute("port").as_int();
        if (_port == 0)
            _port = DEFAULT_PORT;
}


void Zia::Server::setDefaultConfig()
{
        _config.name = "Default Zia";
        _config.version = "0.0.0";
        _port = DEFAULT_PORT;
}

void Zia::Server::setPlatform()
{
    switch(PLATFORM)
    {
        case 0 : _config.platform = API::ServerConfig::Platform::Linux;
            break;
        case 1 : _config.platform = API::ServerConfig::Platform::Windows;
            break;
        case 2 : _config.platform = API::ServerConfig::Platform::Macos;
            break;
    }

}

void Zia::Server::printStartMessage()
{
        std::cout << "Server name : " << _config.name << std::endl;
        std::cout << "Server Version :" << _config.version << std::endl << std::endl;
        std::cout << _port << std::endl;
        std::cout << " _______   _ " << std::endl;
        std::cout << "|_  /_ _| /_\\"  << std::endl;
        std::cout << " / / | | / _ \\"  << std::endl;
        std::cout << "/___|___/_/ \\_\\" << std::endl << std::endl;
}

void Zia::Server::stop()
{
        io_service_g.stop();
}

void Zia::Server::start()
{
    //loadModules();
    accept();
    io_service_g.run_one();
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
                    _port, this->_requestsHanler)->start();
                std::cout << "New Connection !    IP : " << ip <<std::endl;
			}
			accept();
		});
	}
