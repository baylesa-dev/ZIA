/*
** EPITECH PROJECT, 2019
** zia
** File description:
** zia
*/

#pragma once

#include <iostream>
#include <string>
#include "Zia/API.hpp"
#include <fstream>
#include "SSLRequestHandler.hpp"

namespace Zia
{
namespace Modules
{

class SSLModule : public API::Module
{
public:

    const std::string& getName() const override
    {
        return _name;
    }

    API::RequestHandler::pointer newRequestHandler() override
    {
        return std::make_shared<SSLRequestHandler>(_sslContext);
    }

    void onActivate(const API::ServerConfig& cfg) override
    {
        std::cout << "SSL onActivate() !" << std::endl;
    }
    void onDeactivate()
    {
        std::cout << "SSL onDeactivate() !" << std::endl;
    }
    void onConfigChange(const API::ServerConfig& cfg) override
    {
        createContextSSL(cfg);
        std::cout << "SSL onConfigChange() !" << std::endl;
    }

private:
    std::string _name = "SSL";
    std::shared_ptr<boost::asio::ssl::context> _sslContext;
    inline static const std::string certificate = "tls_certificate_path";
    inline static const std::string privateKey = "tls_private_key_path";
    

    std::string loadFile(std::string const &path) const {
        std::ifstream ifs(path);

        if (!ifs.is_open())
            throw std::runtime_error(std::string("file <" + path + "> not found").c_str());

        return std::string((std::istreambuf_iterator<char>(ifs)),
                           (std::istreambuf_iterator<char>()));
    }

    void createContextSSL(const API::ServerConfig &cfg) {
        if (cfg.config.find(certificate) == cfg.config.end() ||
            cfg.config.find(privateKey) == cfg.config.end())
            throw std::runtime_error(std::string("missing config properties (<" + certificate + "> or/and <" + privateKey + ">)").c_str());

        auto cert = loadFile(cfg.config.at(certificate));
        auto pvt_key = loadFile(cfg.config.at(privateKey));

        _sslContext = std::make_shared<boost::asio::ssl::context>(boost::asio::ssl::context::tlsv12_server);
        _sslContext->set_options(
                boost::asio::ssl::context::tlsv12_server |
                boost::asio::ssl::context::no_tlsv1_1);

        _sslContext->use_certificate_chain(
                boost::asio::buffer(cert.data(), cert.size()));

        _sslContext->use_private_key(
                boost::asio::buffer(pvt_key.data(), pvt_key.size()),
                boost::asio::ssl::context::file_format::pem);
    }
    
};

}
} // namespace Zia