#include "clDate.h"

clDate::clDate(int day, int month, int year) : day(day), month(month), year(year) {}

bool clDate::operator<(const clDate& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}

std::istream& operator>>(std::istream& in, clDate& date) {
    std::cout << "(день мес€ц год): ";
    in >> date.day >> date.month >> date.year;
    return in;
}

std::ostream& operator<<(std::ostream& out, const clDate& date) {
    if (date.day < 10) out << '0';
    out << date.day << '.';
    if (date.month < 10) out << '0';
    out << date.month << '.' << date.year;
    return out;
}
