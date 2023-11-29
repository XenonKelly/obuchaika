#include <cstdlib>
#include<iostream>

#include "menu_functions.hpp"

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

const KLikhosherstova::MenuItem* KLikhosherstova::exit(const MenuItem* current) {
	std::exit(0);
}

const KLikhosherstova::MenuItem* KLikhosherstova::study_algebra(const MenuItem* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const KLikhosherstova::MenuItem* KLikhosherstova::study_mathan(const MenuItem* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const KLikhosherstova::MenuItem* KLikhosherstova::study_summ(const MenuItem* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const KLikhosherstova::MenuItem* KLikhosherstova::study_substract(const MenuItem* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const KLikhosherstova::MenuItem* KLikhosherstova::study_multiply(const MenuItem* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const KLikhosherstova::MenuItem* KLikhosherstova::study_divide(const MenuItem* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}


const KLikhosherstova::MenuItem* KLikhosherstova::study_int(const MenuItem* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const KLikhosherstova::MenuItem* KLikhosherstova::study_diff(const MenuItem* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const KLikhosherstova::MenuItem* KLikhosherstova::go_back(const MenuItem* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent->parent;
}
