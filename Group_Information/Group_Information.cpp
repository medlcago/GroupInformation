#include <iostream>

#include "clStudent.h"
#include "clDate.h"
#include "clSemester.h"
#include "clSesion.h"
#include "clGroup.h"

int main() {
    system("chcp 1251");
    system("cls");

    clGroup group;
    std::cin >> group;
    system("cls");
    group.printGroupInformation(std::cout);
    std::cout << group;
    group.sort_students();
    std::cout << group;

    clStudent students;
    students.create_students();
    students.list_of_debtors();
    return 0;
}


