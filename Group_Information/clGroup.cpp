#include <iomanip>
#include "clGroup.h"

clGroup::clGroup() {}

clGroup::clGroup(std::string name, std::string institute, std::string department, std::string curator, int size) : name(name), institute(institute), department(department), curator(curator), size(size) {
    this->students = new clStudent[size];
}

clGroup::~clGroup() {
    delete[] students;
}

int clGroup::get_size() const {
    return size;
}

void clGroup::readFromStream(std::istream& in) {
    std::cout << "Введите название группы: ";
    getline(in, name);
    std::cout << "Введите институт: ";
    getline(in, institute);
    std::cout << "Введите кафедру: ";
    getline(in, department);
    std::cout << "Введите куратора: ";
    getline(in, curator);
    std::cout << "Введите численность группы: ";
    in >> size;

    in.ignore(32767, '\n');

    std::cout << std::endl;

    if (students != nullptr) {
        delete[] students;
    }
    students = new clStudent[size];

    for (int i = 0; i < size; i++) {
        std::cout << "Студент #" << i + 1 << ": " << std::endl;
        in >> students[i];
        std::cout << std::endl;
    }
}

void clGroup::printGroupInformation(std::ostream& out) const {
    out << std::left << std::setw(20) << "Название группы"
        << std::setw(20) << "Институт"
        << std::setw(20) << "Кафедра"
        << std::setw(20) << "Куратор"
        << std::setw(20) << "Численность группы" << '\n';
    out << std::left << std::setw(20) << name
        << std::setw(20) << institute
        << std::setw(20) << department
        << std::setw(20) << curator
        << std::setw(20) << size << '\n';
    out << kLineSeparator;
    out << std::endl;
}

void clGroup::writeToStream(std::ostream& out) const {
    for (int i = 0; i < size; i++) {
        out << "Студент #" << i + 1 << ":\n";
        out << students[i];
    }
    std::cout << kLineSeparator;
    out << std::endl;
}

void clGroup::sort_students() {
    for (int i = 1; i < size; i++) {
        clStudent key = students[i];
        int j = i - 1;

        while (j >= 0 && students[j] < key) {
            students[j + 1] = students[j];
            j--;
        }

        students[j + 1] = key;
    }
}

clStudent& clGroup::operator[](int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return students[index];
}

void clGroup::print_debtors(std::ostream& out, int min_grade) const {
    out << "Задолженники:\n";
    for (int i = 0; i < size; i++) {
        bool is_debtor = false;
        for (int j = 0; j < students[i].sessions.size(); j++) {
            for (const auto& session : students[i].sessions[j]) {
                if (session.grade > 0 && session.grade < min_grade) {
                    if (!is_debtor) {
                        out << "ФИО студента: " << students[i].surname << ' ' << students[i].name << ' ' << students[i].patronymic << '\n';
                        out << "Семестр: " << j + 1 << '\n';
                        is_debtor = true;
                    }
                    out << "Предмет: " << session.discipline << '\n';
                }
            }
            if (is_debtor) {
                break;
            }
        }
        if (is_debtor) {
            out << '\n';
        }
    }
    out << kLineSeparator;
}




void clGroup::student_achievement(std::ostream& out) const {
    for (int i = 0; i < size; i++) {
        out << "Студент #" << i + 1 << ":\n";
        students[i].print_sessions(out);
        out << std::endl;
    }
}

std::istream& operator>>(std::istream& in, clGroup& group) {
    group.readFromStream(in);
    return in;
}

std::ostream& operator<<(std::ostream& out, const clGroup& group) {
    group.writeToStream(out);
    return out;
}
