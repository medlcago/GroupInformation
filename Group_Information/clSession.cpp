#include "clSession.h"
#include <string>

clSession::clSession(std::string discipline, clDate date, int grade, std::string teacher){
    this->discipline = discipline;
    this->date = date;
    this->grade = grade;
    this->teacher = teacher;
}