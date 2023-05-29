#include <iostream>
#include <string>
#include <random>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <vector>

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
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> grade_distribution(2, 5);
    std::vector<std::pair<std::string, std::string>> subjects = {
        {"Средства вычислительной техники", "Матюхина Е.Н."},
        {"Физика", "Волков Г.С."},
        {"Языки программирования", "Филатов В.В."},
        {"Правоведение", "Мазеин А.В."},
        {"Математический анализ", "Головешкин В.А."},
        {"Иностранный язык", "Виноградова М.В."}
    };

    for (int i = 0; i < group.get_size(); i++) {
        for (int j = 1; j <= 2; j++) {
            std::shuffle(subjects.begin(), subjects.end(), gen);
            for (int k = 0; k < subjects.size(); k++) {
                int grade = grade_distribution(gen);
                auto subject_teacher_pair = subjects[k];
                group[i].add_session(j, clSession(subject_teacher_pair.first, clDate(1, 1, 2020), grade, subject_teacher_pair.second));
            }
        }
    }
    
    group.print_debtors(std::cout, 3);

    return 0;
}


