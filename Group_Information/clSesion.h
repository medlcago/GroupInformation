#pragma once

#include <string>
#include "clDate.h"

class clSesion {
public:
    std::string discipline_name;
    clDate submission_date;
    int grade;
    std::string teacher;

    clSesion(std::string discipline_name, clDate submission_date, int grade, std::string teacher);
};

