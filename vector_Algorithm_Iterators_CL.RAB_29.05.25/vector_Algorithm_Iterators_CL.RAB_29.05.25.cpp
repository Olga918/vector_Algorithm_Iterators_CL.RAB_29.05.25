// vector_Algorithm_Iterators_CL.RAB_29.05.25.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm> // для sort, min_element, max_element, remove, for_each
#include <functional> // для greater

int main() {
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

    return 0;
}