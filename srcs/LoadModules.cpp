/*
** EPITECH PROJECT, 2019
** Zia
** File description:
** LoadModules
*/

#include "LoadModules.hpp"
#include "API.hpp"
#include <iostream>
#include <dlfcn.h>

Zia::LoadModules::LoadModules()
{
}

Zia::LoadModules::~LoadModules()
{
}

bool Zia::LoadModules::loadAllModules(
    std::vector<API::Module::pointer> &allModules,
    std::vector<std::string> allModulesPath,
    std::string configPath,
    API::ServerConfig &cfg)
{
    void *handle;

    for (auto &path : allModulesPath) {
        handle = dlopen(path.c_str(), RTLD_LAZY);
        if (handle) {
            this->_loadmodule.push_back(handle);
            API::Module::factory factory = (API::Module::factory)dlsym(handle, "factory");
            if (factory) {
                API::Module::pointer mod = factory();
                std::cout << "Module " << mod->getName() << " is load !" << std::endl;
                mod->onActivate(_getModuleConfig(mod->getName(), cfg, configPath));
                allModules.push_back(mod);
            } else {
                std::cerr << dlerror() << std::endl;
                dlclose(handle);
            }
            handle = NULL;
        }
        else
            std::cerr << "dlopen fail !" << std::endl;
    }
}

void Zia::LoadModules::closeAllModules(std::vector<API::Module::pointer> &allModules)
{
    for (int i = 0; i != this->_loadmodule.size(); i++) {
        allModules.at(i)->onDeactivate();
        dlclose(this->_loadmodule.at(i));
    }
}

Zia::API::ServerConfig &Zia::LoadModules::_getModuleConfig(std::string modName,
                                                      API::ServerConfig &cfg,
                                                      std::string configPath)
{
    pugi::xml_document config;
    pugi::xml_parse_result result = config.load_file(configPath.c_str());
    pugi::xml_node_iterator it = config.child("server").child("modules").child(modName.c_str());
    for (pugi::xml_attribute_iterator ait = it->attributes_begin(); ait != it->attributes_end(); ++ait)
    {
        cfg.config[ait->name()] = ait->value();
    }
    return (cfg);
}
