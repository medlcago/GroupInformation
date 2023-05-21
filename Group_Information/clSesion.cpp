#include "clSesion.h"

clSesion::clSesion(std::string discipline_name, clDate submission_date, int grade, std::string teacher) :
    discipline_name(discipline_name), submission_date(submission_date), grade(grade), teacher(teacher) {}
