#pragma once
#include <string>

#include "clDate.h"

class clSession
{
public:
    std::string discipline;
    clDate date;
    int grade;
    std::string teacher;

    clSession(std::string discipline, clDate date, int grade, std::string teacher);
};


