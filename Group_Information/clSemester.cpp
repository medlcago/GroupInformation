#include "clSemester.h"

clSemester::clSemester(int semester_number) : semester_number(semester_number) {}

void clSemester::add_session(clSesion session) {
    sessions.push_back(session);
}

clSesion* clSemester::get_session(int discipline_number) {
    if (discipline_number < 0 || discipline_number >= sessions.size()) {
        return nullptr;
    }
    return &sessions[discipline_number];
}
