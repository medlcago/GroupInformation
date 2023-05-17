#pragma once
#include <iostream>

class clDate {
private:
    int day;
    int month;
    int year;
public:
    clDate(int day = 1, int month = 1, int year = 1970);

    bool operator<(const clDate& other) const;

    friend std::istream& operator>>(std::istream& in, clDate& date);
    friend std::ostream& operator<<(std::ostream& out, const clDate& date);
};


