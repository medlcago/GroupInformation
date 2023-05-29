#include "clStudent.h"
#include "clGroup.h"

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

void clStudent::add_session(int semester, const clSession& session) {
    if (semester < 1) {
        throw std::out_of_range("Semester out of range");
    }
    if (semester > sessions.size()) {
        sessions.resize(semester);
    }
    sessions[semester - 1].push_back(session);
}

void clStudent::remove_session(int semester, int discipline_index) {
    if (semester < 1 || semester > sessions.size()) {
        throw std::out_of_range("Semester out of range");
    }
    if (discipline_index < 1 || discipline_index > sessions[semester - 1].size()) {
        throw std::out_of_range("Discipline index out of range");
    }
    sessions[semester - 1].erase(sessions[semester - 1].begin() + discipline_index - 1);
}

void clStudent::print_sessions(std::ostream& out) const {
    out << "ФИО студента: " << surname << " " << name << " " << patronymic << '\n';
    for (int i = 0; i < sessions.size(); i++) {
        out << "Семестр " << i + 1 << ":\n\n";
        for (const auto& session : sessions[i]) {
            out << "Дисциплина: " << session.discipline << '\n';
            out << "Дата: " << session.date << '\n';
            out << "Оценка: " << session.grade << '\n';
            out << "Преподаватель: " << session.teacher << "\n\n";
        }
    }
    out << kLineSeparator;
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
