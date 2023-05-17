#pragma once
#include <iostream>
#include <string>
#include "clStudent.h"

const unsigned kLineWidth = 100;
const std::string kLineSeparator(kLineWidth, '-');


class clGroup {
protected:
    std::string name;
    std::string institute;
    std::string department;
    std::string curator;
    int size;
    clStudent* students;

public:
    clGroup();

    clGroup(std::string name, std::string institute, std::string department, std::string curator, int size);

    ~clGroup();

    void readFromStream(std::istream& in);

    void printGroupInformation(std::ostream& out) const;

    void writeToStream(std::ostream& out) const;

    void sort_students();

    clStudent& operator[](int index);

    friend std::istream& operator>>(std::istream& in, clGroup& group);
    friend std::ostream& operator<<(std::ostream& out, const clGroup& group);
};


