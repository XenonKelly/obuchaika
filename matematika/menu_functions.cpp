#include <cstdlib>
#include<iostream>
#include <random>

#include "menu_functions.hpp"

// Вспомогательные функции для этой единицы трансляции должны быть объявлены 
// внутри этой единицы трансляции (хедер не является единицей трансляции) 
// в анонимном namespace. Тогда при объединении линкером всех имён в один файл 
// не будет конфликта. И располагаем их по алфавиту.
namespace {
    const KLikhosherstova::MenuItem* choose_continuation(const KLikhosherstova::MenuItem* option);
    int get_random_number();
}

// Логика расположения функций в отношении <1 функция> == <n элементов меню>
//      - расположение вверху и по алфавиту
const KLikhosherstova::MenuItem* KLikhosherstova::go_back(const MenuItem* current) {
    return current->parent->parent;
}

const KLikhosherstova::MenuItem* KLikhosherstova::exit(const MenuItem* current) {
	std::exit(0);
}

const KLikhosherstova::MenuItem* KLikhosherstova::show_menu(const MenuItem* current) {
    for (int i = 1; i < current->children_count; i++) {
        std::cout << current->children[i]->title << std::endl;
    }
    std::cout << current->children[0]->title << std::endl;
    std::cout << "Выберите действие >> ";

    int user_input;
    std::cin >> user_input;
    std::cout << std::endl;

    return current->children[user_input];
}

// Логика расположения функций в отношении <1 функция> == <1 элемент меню>
//      - повторяем такое же расположение как в меню
const KLikhosherstova::MenuItem* KLikhosherstova::study_algebra(const MenuItem* current) {
    return current->parent;
}

const KLikhosherstova::MenuItem* KLikhosherstova::study_mathan(const MenuItem* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const KLikhosherstova::MenuItem* KLikhosherstova::algebra_summ(const MenuItem* current) {
    int summ;
    int a = get_random_number();
    int b = get_random_number();
    std::cout << "Сколько будет " << a << " + " << b << " = ";
    std::cin >> summ;
    while (summ != (a + b)) {
        std::cout << "Неверный ответ! Попробуйте снова" << std::endl;
        std::cin >> summ;
    } 
    return choose_continuation(current);
}

const KLikhosherstova::MenuItem* KLikhosherstova::algebra_substract(const MenuItem* current) {
    int difference;
    int a = get_random_number();
    int b = get_random_number();
    std::cout << "Сколько будет " << a << " - " << b << " = ";
    std::cin >> difference;
    while (difference != (a - b)) {
        std::cout << "Неверный ответ! Попробуйте снова" << std::endl;
        std::cin >> difference;
    }
    return choose_continuation(current);  
}

const KLikhosherstova::MenuItem* KLikhosherstova::algebra_multiply(const MenuItem* current) {
    int product;
    int a = get_random_number();
    int b = get_random_number();
    std::cout << "Сколько будет " << a << " * " << b << " = ";
    std::cin >> product;
    while (product != (a * b)) {
        std::cout << "Неверный ответ! Попробуйте снова" << std::endl;
        std::cin >> product;
    }
    return choose_continuation(current);
}

const KLikhosherstova::MenuItem* KLikhosherstova::algebra_divide(const MenuItem* current) {
    int quotient;
    int a = get_random_number();
    int b = get_random_number();
    std::cout << "Сколько будет " << a << " : " << b << " = ";
    std::cin >> quotient;
    while (quotient != (a / b)) {
        std::cout << "Неверный ответ! Попробуйте снова" << std::endl;
        std::cin >> quotient;
    }
    return choose_continuation(current);
}

const KLikhosherstova::MenuItem* KLikhosherstova::mathan_diff(const MenuItem* current) {
    return current->parent;
}

const KLikhosherstova::MenuItem* KLikhosherstova::mathan_int(const MenuItem* current) {
    return current->parent;
}

namespace {
    const KLikhosherstova::MenuItem* choose_continuation(const KLikhosherstova::MenuItem* option) {
        std::cout << "Хотите продолжить?" << std::endl;
        std::cout << "1 - Хочу продолжить решать примеры этой категории" << std::endl;
        std::cout << "0 - Выйти в меню" << std::endl;

        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1:
                return option;
                break;
            case 0:
                return option->parent;
                break;
        }
    }

    int get_random_number() {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> num(10, 50);

        return num(rng);
    }
}
