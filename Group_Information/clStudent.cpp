#include "clStudent.h"

clStudent::clStudent() {}

clStudent::clStudent(std::string surname, std::string name, std::string patronymic, clDate birthdate, std::string gender, clDate enrollment_date, int scholarship) {
    this->surname = surname;
    this->name = name;
    this->patronymic = patronymic;
    this->birthdate = birthdate;
    this->gender = gender;
    this->enrollment_date = enrollment_date;
    this->scholarship = scholarship;
}

clStudent& clStudent::operator=(const clStudent& other) {
    this->surname = other.surname;
    this->name = other.name;
    this->patronymic = other.patronymic;
    this->birthdate = other.birthdate;
    this->gender = other.gender;
    this->enrollment_date = other.enrollment_date;
    this->scholarship = other.scholarship;
    return *this;
}

bool clStudent::operator<(const clStudent& other) const {
    if (scholarship != other.scholarship) return scholarship < other.scholarship;
    return gender < other.gender;
}

std::istream& operator>>(std::istream& in, clStudent& student) {
    std::cout << "Введите фамилию студента: ";
    in >> student.surname;
    in.ignore(32768, '\n');

    std::cout << "Введите имя студента: ";
    in >> student.name;
    in.ignore(32768, '\n');

    std::cout << "Введите отчество студента: ";
    in >> student.patronymic;
    in.ignore(32768, '\n');

    std::cout << "Введите дату рождения студента: ";
    in >> student.birthdate;
    in.ignore(32768, '\n');

    std::cout << "Введите пол студента: ";
    in >> student.gender;
    in.ignore(32768, '\n');

    std::cout << "Введите дату зачисления студента: ";
    in >> student.enrollment_date;
    in.ignore(32768, '\n');

    std::cout << "Введите стипендию студента: ";
    in >> student.scholarship;
    in.ignore(32768, '\n');

    std::cout << std::endl;
    return in;
}

std::ostream& operator<<(std::ostream& out, const clStudent& student) {
    out << "Фамилия: " << student.surname << '\n';
    out << "Имя: " << student.name << '\n';
    out << "Отчество: " << student.patronymic << '\n';
    out << "Дата рождения: " << student.birthdate << '\n';
    out << "Пол: " << student.gender << '\n';
    out << "Дата зачисления: " << student.enrollment_date << '\n';
    out << "Размер стипендии: " << student.scholarship << '\n';
    out << std::endl;
    return out;
}
