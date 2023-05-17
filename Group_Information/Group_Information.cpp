#include <iostream>
#include <Windows.h>

#include "clDate.h"
#include "clStudent.h"
#include "clGroup.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    clGroup group;
    cin >> group;
    system("cls");
    group.printGroupInformation(cout);
    cout << group;
    group.sort_students();
    cout << group;
    return 0;
}
