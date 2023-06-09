#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <limits>

#include "clGroup.h"
#include "LinkedList.h"


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
    
    LinkedList<std::pair<std::string, std::string>> subjects;
    subjects.push_back({ "Средства вычислительной техники", "Матюхина Е.Н." });
    subjects.push_back({ "Физика", "Волков Г.С." });
    subjects.push_back({ "Языки программирования", "Филатов В.В." });
    subjects.push_back({ "Правоведение", "Мазеин А.В." });
    subjects.push_back({ "Математический анализ", "Головешкин В.А." });
    subjects.push_back({ "Иностранный язык", "Виноградова М.В." });

    for (int i = 0; i < group.get_size(); i++) {
        for (int j = 1; j <= 2; j++) {
            subjects.shuffle(gen);
            for (int k = 0; k < subjects.getSize(); k++) {
                int grade = grade_distribution(gen);
                auto subject_teacher_pair = subjects[k];
                group[i].add_session(j, clSession(subject_teacher_pair.first, clDate(1, 1, 2020), grade, subject_teacher_pair.second));
            }
        }
    }
    
    group.print_debtors(std::cout, 3);

    return 0;
}

