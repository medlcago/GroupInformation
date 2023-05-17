#include <iostream>
#include <Windows.h>

#include "clDate.h"
#include "clStudent.h"
#include "clGroup.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    clGroup group;
    std::cin >> group;
    system("cls");
    group.printGroupInformation(std::cout);
    std::cout << group;
    group.sort_students();
    std::cout << group;
    return 0;
}
