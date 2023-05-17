#pragma once
#include <iostream>
#include <string>
#include "clDate.h"

class clStudent {
protected:
    std::string surname;
    std::string name;
    std::string patronymic;
    clDate birthdate;
    std::string gender;
    clDate enrollment_date;
    int scholarship;
public:
    clStudent();

    clStudent(std::string surname, std::string name, std::string patronymic, clDate birthdate, std::string gender, clDate enrollment_date, int scholarship);

    clStudent& operator=(const clStudent& other);

    bool operator<(const clStudent& other) const;

    friend class clGroup;
    friend std::istream& operator>>(std::istream& in, clStudent& student);
    friend std::ostream& operator<<(std::ostream& out, const clStudent& student);
};


