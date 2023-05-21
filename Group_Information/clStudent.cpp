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
        if (semester.semester_number == 2) { // текущий семестр
            return *semester.get_session(discipline_number);
        }
    }
    throw std::out_of_range("Invalid discipline number");
}

std::vector<clStudent> clStudent::create_students() {
    std::vector<clStudent> students;

    clStudent student1("Королев", "Александр", "Андреевич", clDate(1, 1, 2003), "М", clDate(8, 8, 2022), 6000);
    clSemester semester1(1); // первый семестр
    semester1.add_session(clSesion("Математика", clDate(31, 12, 2018), 5, "Иванов И.И."));
    semester1.add_session(clSesion("Физика", clDate(31, 12, 2018), 4, "Петров П.П."));
    student1.add_semester(semester1);
    students.push_back(student1);

    clStudent student2("Гончарова", "Александра", "Ивановна", clDate(18, 9, 2004), "Ж", clDate(9, 8, 2022), 9000);
    clSemester semester2(2); // второй семестр
    semester2.add_session(clSesion("Математика", clDate(30, 6, 2019), 3, "Иванов И.И."));
    semester2.add_session(clSesion("Физика", clDate(30, 6, 2019), 2, "Петров П.П.")); // задолженность
    student2.add_semester(semester2);
    students.push_back(student2);

    return students;
}

bool clStudent::has_debts() const {
    for (const auto& semester : semesters) {
        for (const auto& session : semester.sessions) {
            if (session.grade == 2) { // если оценка равна 2
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
    std::cout << "Список должников:\n";
    bool has_debtors = false;
    for (const auto& student : students) {
        if (student.has_debts()) {
            has_debtors = true;
            std::cout << student;
        }
    }
    if (!has_debtors) {
        std::cout << "Нет должников\n";
    }
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
