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

void clStudent::add_semester(clSemester semester) {
    semesters.push_back(semester);
}

clSesion* clStudent::get_session(int semester_number, int discipline_number) {
    for (auto& semester : semesters) {
        if (semester.semester_number == semester_number) {
            return semester.get_session(discipline_number);
        }
    }
    return nullptr;
}

clSesion& clStudent::operator[](int discipline_number) {
    for (auto& semester : semesters) {
        if (semester.semester_number == 2) { // ������� �������
            return *semester.get_session(discipline_number);
        }
    }
    throw std::out_of_range("Invalid discipline number");
}

std::vector<clStudent> clStudent::create_students() {
    std::vector<clStudent> students;

    clStudent student1("�������", "���������", "���������", clDate(1, 1, 2003), "�", clDate(8, 8, 2022), 6000);
    clSemester semester1(1); // ������ �������
    semester1.add_session(clSesion("����������", clDate(31, 12, 2018), 5, "������ �.�."));
    semester1.add_session(clSesion("������", clDate(31, 12, 2018), 4, "������ �.�."));
    student1.add_semester(semester1);
    students.push_back(student1);

    clStudent student2("���������", "����������", "��������", clDate(18, 9, 2004), "�", clDate(9, 8, 2022), 9000);
    clSemester semester2(2); // ������ �������
    semester2.add_session(clSesion("����������", clDate(30, 6, 2019), 3, "������ �.�."));
    semester2.add_session(clSesion("������", clDate(30, 6, 2019), 2, "������ �.�.")); // �������������
    student2.add_semester(semester2);
    students.push_back(student2);

    return students;
}

bool clStudent::has_debts() const {
    for (const auto& semester : semesters) {
        for (const auto& session : semester.sessions) {
            if (session.grade == 2) { // ���� ������ ����� 2
                return true;
            }
        }
    }
    return false;
}

std::string clStudent::get_surname() const {
    return surname;
}

std::string clStudent::get_name() const {
    return name;
}

std::string clStudent::get_patronymic() const {
    return patronymic;
}

void clStudent::list_of_debtors() const {
    std::vector<clStudent> students = create_students();
    std::cout << "������ ���������:\n";
    bool has_debtors = false;
    for (const auto& student : students) {
        if (student.has_debts()) {
            has_debtors = true;
            std::cout << student;
        }
    }
    if (!has_debtors) {
        std::cout << "��� ���������\n";
    }
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
