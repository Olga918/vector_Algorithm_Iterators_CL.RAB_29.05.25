// vector_Algorithm_Iterators_CL.RAB_29.05.25.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <memory>
#include <iterator>

int main() {

  /*  1.
        В контейнере типа vector хранится набор целых чисел.Використайте алгоритми для решения следующих задач :
    1.	Поиск минимального значения.
        2.	Поиск максимального значения.
        3.	Сортировка данных по убыванию.
        4.	Сортировка данных по возрастанию.
        5.	Увеличение значений в контейнере в певну кількість разів(множення)
        6.	Уменьшение значений в контейнере  в певну кількість разів(ділення).
        7.	Удаление элементов из контейнера равных искомому значению.*/


    std::cout << "=== Task 1: Algorithms for vector ===\n";

    // Исходный вектор с целыми числами
    std::vector<int> vec = { 10, 25, 15, 20, 25, 5, 30 };

    // 1. Поиск минимального значения
    auto min_it = std::min_element(vec.begin(), vec.end());
    if (min_it != vec.end())
        std::cout << "1) Minimum value: " << *min_it << "\n";

    // 2. Поиск максимального значения
    auto max_it = std::max_element(vec.begin(), vec.end());
    if (max_it != vec.end())
        std::cout << "2) Maximum value: " << *max_it << "\n";

    // 3. Сортировка по убыванию
    std::vector<int> vec_desc = vec;
    std::sort(vec_desc.begin(), vec_desc.end(), std::greater<int>());
    std::cout << "3) Sort in descending order: ";
    for (int val : vec_desc) std::cout << val << " ";
    std::cout << "\n";

    // 4. Сортировка по возрастанию
    std::vector<int> vec_asc = vec;
    std::sort(vec_asc.begin(), vec_asc.end());
    std::cout << "4) Sort by ascending order: ";
    for (int val : vec_asc) std::cout << val << " ";
    std::cout << "\n";

    // 5. Увеличение значений в контейнере в несколько раз (умножение)
    const int multiplier = 3;
    std::vector<int> vec_multiplied = vec;
    for (int& x : vec_multiplied) {
        x = x * multiplier;
    }
    std::cout << "5) after increasing in " << multiplier << " times: ";
    for (int val : vec_multiplied) std::cout << val << " ";
    std::cout << "\n";

    // 6. Уменьшение значений в контейнере в несколько раз (деление)
    const int divisor = 2;
    std::vector<int> vec_divided = vec;
    for (int& x : vec_divided) {
        x = x / divisor;  // Целочисленное деление
    }
    std::cout << "6) After decreasing in " << divisor << " times: ";
    for (int val : vec_divided) std::cout << val << " ";
    std::cout << "\n";

    // 7. Удаление элементов, равных искомому значению
    int value_to_remove = 25;
    std::vector<int> vec_removed = vec;
    vec_removed.erase(std::remove(vec_removed.begin(), vec_removed.end(), value_to_remove), vec_removed.end());
    std::cout << "7) After removing the value " << value_to_remove << ": ";
    for (int val : vec_removed) std::cout << val << " ";
    std::cout << "\n";


    /////////////////////////////////////////////////////////

    //2.
    //    1 Створити динамический массив з вашими  оцінками(умній указатель)
    //    2. Створити вектор і загнати у нього цей масив оцінок
    //    3. Додати в кінець ще оцінку за екзамен(способами copy / inserter / back_inserter 
    //        / двома різними методами класу vector / insert_iterator / back_insert_iterator)
    //    4. Вставити в початок вектору массив оцінок за тести{ 12,11,12 }
    //    5. Вивести на екран трьома способами : через[] / at() / iterator  доступа


     // === ЗАДАНИЕ 2: Оценки (vector + умный указатель) ===

    std::cout << "\n=== Task 2: Ratings (Smart pointer + vector) ===\n";

    std::unique_ptr<int[]> marks(new int[5] {10, 12, 9, 11, 10});
    int size = 5;
    std::vector<int> grades(marks.get(), marks.get() + size);

    int exam_mark = 13;

    grades.push_back(exam_mark);                      // способ 1
    grades.insert(grades.end(), exam_mark);           // способ 2

    std::vector<int> exam_vec = { exam_mark };
    std::copy(exam_vec.begin(), exam_vec.end(), std::back_inserter(grades)); // способ 3

    std::insert_iterator<std::vector<int>> it(grades, grades.end());
    std::copy(exam_vec.begin(), exam_vec.end(), it);  // способ 4

    std::back_insert_iterator<std::vector<int>> b_it(grades);
    *b_it = exam_mark;                                 // способ 5

    std::vector<int> test_scores = { 12, 11, 12 };
    grades.insert(grades.begin(), test_scores.begin(), test_scores.end());

    std::cout << "Output via []: ";
    for (size_t i = 0; i < grades.size(); ++i)
        std::cout << grades[i] << " ";
    std::cout << "\n";

    std::cout << "Output via at(): ";
    for (size_t i = 0; i < grades.size(); ++i)
        std::cout << grades.at(i) << " ";
    std::cout << "\n";

    std::cout << "Output via iterator: ";
    for (auto iter = grades.begin(); iter != grades.end(); ++iter)
        std::cout << *iter << " ";
    std::cout << "\n";

///////////////////////////////////////////////////////

   /* 3.  Виконати друге завдання на контейнері list<int>*/

    // === ЗАДАНИЕ 3: Те же действия, но с list<int> ===
    std::cout << "\n=== Task 3: Ratings (list<int>) ===\n";

    std::unique_ptr<int[]> marks_list(new int[5] {10, 12, 9, 11, 10});
    std::list<int> grade_list(marks_list.get(), marks_list.get() + 5);

    grade_list.push_back(exam_mark);              // способ 1
    grade_list.insert(grade_list.end(), exam_mark); // способ 2

    std::back_insert_iterator<std::list<int>> list_back_it(grade_list);
    *list_back_it = exam_mark;

    std::list<int> test_scores_list = { 12, 11, 12 };
    grade_list.insert(grade_list.begin(), test_scores_list.begin(), test_scores_list.end());

    std::cout << "Ratings (list): ";
    for (int val : grade_list)
        std::cout << val << " ";
    std::cout << "\n";

    return 0;
}