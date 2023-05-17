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
    std::cout << "������� ������� ��������: ";
    in >> student.surname;
    in.ignore(32768, '\n');

    std::cout << "������� ��� ��������: ";
    in >> student.name;
    in.ignore(32768, '\n');

    std::cout << "������� �������� ��������: ";
    in >> student.patronymic;
    in.ignore(32768, '\n');

    std::cout << "������� ���� �������� ��������: ";
    in >> student.birthdate;
    in.ignore(32768, '\n');

    std::cout << "������� ��� ��������: ";
    in >> student.gender;
    in.ignore(32768, '\n');

    std::cout << "������� ���� ���������� ��������: ";
    in >> student.enrollment_date;
    in.ignore(32768, '\n');

    std::cout << "������� ��������� ��������: ";
    in >> student.scholarship;
    in.ignore(32768, '\n');

    std::cout << std::endl;
    return in;
}

std::ostream& operator<<(std::ostream& out, const clStudent& student) {
    out << "�������: " << student.surname << '\n';
    out << "���: " << student.name << '\n';
    out << "��������: " << student.patronymic << '\n';
    out << "���� ��������: " << student.birthdate << '\n';
    out << "���: " << student.gender << '\n';
    out << "���� ����������: " << student.enrollment_date << '\n';
    out << "������ ���������: " << student.scholarship << '\n';
    out << std::endl;
    return out;
}
