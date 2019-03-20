/*
** EPITECH PROJECT, 2019
** Zia
** File description:
** Server cpp
*/

#include <vector>
#include <string>

#include "Server.hpp"
#include "ArgsParser.hpp"
#include "ServerClient.hpp"

boost::asio::io_service io_service;

Zia::Server::Server(bool *run, unsigned short port, ArgsParser *args)
    : _acceptor(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))
    , _socket(io_service)
    , _port(port)
    , _run(run)
    , _args(args)
{
    setConfig();
    setModulesPath();
    printStartMessage();
    LoadModules moduleLoader;
    _moduleLoader = moduleLoader;
    _moduleLoader.loadAllModules(_allModule, _allModulesPath, _args->getConfigPath(), _config);
    _requestsHanler = std::shared_ptr<RequestsHandler>(new RequestsHandler(_allModule));
}

Zia::Server::~Server()
{
}

void Zia::Server::setConfig()
{
    pugi::xml_document config;
    pugi::xml_parse_result result = config.load_file(_args->getConfigPath().c_str());
    if (!result) {
        std::cout << _args->getConfigPath() << " : "
            << result.description() << std::endl;
        setDefaultConfig();
        return;
    }
    _config.name = config.child("server").attribute("name").value();
    _config.version = config.child("server").attribute("version").value();
}

void Zia::Server::setDefaultConfig()
{
    _config.name = "Default Zia";
    _config.version = "0.0.0";
}

void Zia::Server::setModulesPath()
{
    pugi::xml_document config;
    pugi::xml_parse_result result = config.load_file(_args->getConfigPath().c_str());
    if (!result) {
        std::cout <<"No modules loaded (unable to find config.xml)"<< std::endl;
        return;
    }
    for (pugi::xml_node mod =
        config.child("server").child("modules").first_child(); mod;
        mod = mod.next_sibling()) {
        std::string path(_args->getModulesPath());
        std::string head("zia-");
        std::string name(mod.name());
        std::string ext(".so");

        _allModulesPath.push_back(path + head + name + ext);
    }
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
    std::cout << " _______   _ " << std::endl;
    std::cout << "|_  /_ _| /_\\"  << std::endl;
    std::cout << " / / | | / _ \\"  << std::endl;
    std::cout << "/___|___/_/ \\_\\" << std::endl << std::endl;
}

void Zia::Server::stop()
{
    _moduleLoader.closeAllModules(_allModule);
//    _socket.close();
}

void Zia::Server::start()
{
    accept();
    while(*_run == true)
        io_service.run_one();
    stop();
}

void Zia::Server::accept()
{
    _acceptor.async_accept(_socket,
        [this](boost::system::error_code err) {
        if (!err) {
            std::string ip(_socket.remote_endpoint().address().to_string());
            API::Connection connection;
            connection.addr = ip;
            connection.port = _port;
            std::make_shared<ServerClient>(std::move(_socket),
                                           connection,
                                           _config,
                                           _run,
                                           this->_requestsHanler)->start();
            std::cout << "New Connection !    IP : " << ip << std::endl;
        }
        accept();
    });
}
