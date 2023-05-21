#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "clDate.h"
#include "clSemester.h"

class clStudent {
protected:
    std::string surname;
    std::string name;
    std::string patronymic;
    clDate birthdate;
    std::string gender;
    clDate enrollment_date;
    int scholarship;
    std::vector<clSemester> semesters;

public:
    clStudent();

    clStudent(std::string surname, std::string name, std::string patronymic, clDate birthdate, std::string gender, clDate enrollment_date, int scholarship);

    clStudent& operator=(const clStudent& other);

    bool operator<(const clStudent& other) const;

    void add_semester(clSemester semester);

    clSesion* get_session(int semester_number, int discipline_number);

    clSesion& operator[](int discipline_number);

    static std::vector<clStudent> create_students();

    bool has_debts() const;

    std::string get_surname() const;
    std::string get_name() const;
    std::string get_patronymic() const;

    void list_of_debtors() const;

    friend class clGroup;
    friend std::istream& operator>>(std::istream& in, clStudent& student);
    friend std::ostream& operator<<(std::ostream& out, const clStudent& student);
};


