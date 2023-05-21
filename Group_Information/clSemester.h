#pragma once

#include <vector>
#include "clSesion.h"

class clSemester {
public:
    int semester_number;
    std::vector<clSesion> sessions;

    clSemester(int semester_number);

    void add_session(clSesion session);

    clSesion* get_session(int discipline_number);
};

