#pragma once
#include <string>
#include <vector>

#include "clDate.h"
#include "clSession.h"

class clStudent {
protected:
    std::string surname;
    std::string name;
    std::string patronymic;
    clDate birthdate;
    std::string gender;
    clDate enrollment_date;
    int scholarship;
    std::vector<std::vector<clSession>> sessions;
public:
    clStudent();

    clStudent(std::string surname, std::string name, std::string patronymic, clDate birthdate, std::string gender, clDate enrollment_date, int scholarship);

    clStudent& operator=(const clStudent& other);

    bool operator<(const clStudent& other) const;


    friend class clGroup;
    friend std::istream& operator>>(std::istream& in, clStudent& student);
    friend std::ostream& operator<<(std::ostream& out, const clStudent& student);

    void add_session(int semester, const clSession& session);

    void remove_session(int semester, int discipline_index);

    void print_sessions(std::ostream& out) const;
};


