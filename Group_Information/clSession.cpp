#include "clSession.h"
#include <string>

clSession::clSession(std::string discipline = "", clDate date = clDate(), int grade = 0, std::string teacher = ""){
    this->discipline = discipline;
    this->date = date;
    this->grade = grade;
    this->teacher = teacher;
}