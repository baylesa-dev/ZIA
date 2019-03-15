/*
** EPITECH PROJECT, 2019
** Zia
** File description:
** AssemblesAnswer
*/

#include <iostream>
#include "AssemblesAnswer.hpp"

Zia::AssemblesAnswer::AssemblesAnswer()
{
}

Zia::AssemblesAnswer::~AssemblesAnswer()
{
}

std::string Zia::AssemblesAnswer::run(API::Response &req)
{
    std::string res;
    res = req.protocol + ' ';
    res += std::to_string(req.status_code) + ' ';
    res += req.status_message + '\n';
    for (auto headers : req.headers)
        res = res + headers.first + ": " + headers.second + '\n';
    res = res + '\n';
    for (auto c: req.body)
        res = res + c;
    return res;
}
