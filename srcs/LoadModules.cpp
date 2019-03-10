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
    const API::ServerConfig &cfg)
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
                mod->onActivate(cfg);
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