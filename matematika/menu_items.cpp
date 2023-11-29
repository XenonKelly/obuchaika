#include <cstddef>

#include "menu_items.hpp"
#include "menu_functions.hpp"


const KLikhosherstova::MenuItem KLikhosherstova::STUDY_SUMM = {
    "1 - ���� ��������� ����������!", KLikhosherstova::study_summ, &KLikhosherstova::STUDY_ALGEBRA
};
const KLikhosherstova::MenuItem KLikhosherstova::STUDY_SUBSTRACT = {
    "2 - ���� ��������� ��������!", KLikhosherstova::study_substract, &KLikhosherstova::STUDY_ALGEBRA
};
const KLikhosherstova::MenuItem KLikhosherstova::STUDY_MULTIPLY = {
    "3 - ���� ��������� ��������!", KLikhosherstova::study_multiply, &KLikhosherstova::STUDY_ALGEBRA
};
const KLikhosherstova::MenuItem KLikhosherstova::STUDY_DIVIDE = {
    "4 - ���� ��������� ������!", KLikhosherstova::study_divide, &KLikhosherstova::STUDY_ALGEBRA
};
const KLikhosherstova::MenuItem KLikhosherstova::GO_BACK_FROM_ALGEBRA = {
    "0 - ��������� � ������ ���������", KLikhosherstova::go_back, &KLikhosherstova::STUDY_ALGEBRA
};


namespace {
    const KLikhosherstova::MenuItem* const study_children_from_algebra[] = {
        &KLikhosherstova::GO_BACK_FROM_ALGEBRA,
        &KLikhosherstova::STUDY_SUMM,
        &KLikhosherstova::STUDY_SUBSTRACT,
        &KLikhosherstova::STUDY_MULTIPLY,
        &KLikhosherstova::STUDY_DIVIDE
    };
    const int study_children_from_algebra_size = sizeof(study_children_from_algebra) / sizeof(study_children_from_algebra[0]);
}


const KLikhosherstova::MenuItem KLikhosherstova::STUDY_DIFF = {
    "1 - ���� ������� ���������������� ����������!", KLikhosherstova::study_diff, &KLikhosherstova::STUDY_MATHAN
};
const KLikhosherstova::MenuItem KLikhosherstova::STUDY_INT = {
    "2 - ���� ������� ������������ ����������!", KLikhosherstova::study_int, &KLikhosherstova::STUDY_MATHAN
};
const KLikhosherstova::MenuItem KLikhosherstova::GO_BACK_FROM_MATHAN = {
    "0 - ��������� � ������ ���������", KLikhosherstova::go_back, &KLikhosherstova::STUDY_MATHAN
};

namespace {
    const KLikhosherstova::MenuItem* const study_children_from_mathan[] = {
        &KLikhosherstova::GO_BACK_FROM_MATHAN,
        &KLikhosherstova::STUDY_DIFF,
        &KLikhosherstova::STUDY_INT,
    };
    const int study_children_from_mathan_size = sizeof(study_children_from_mathan) / sizeof(study_children_from_mathan[0]);
}


const KLikhosherstova::MenuItem KLikhosherstova::STUDY_ALGEBRA = {
    "1 - ���� ������� �������!", KLikhosherstova::show_menu, &KLikhosherstova::STUDY, study_children_from_algebra, study_children_from_algebra_size
};

const KLikhosherstova::MenuItem KLikhosherstova::STUDY_MATHAN = {
    "2 - ���� ������� �������������� ������!", KLikhosherstova::show_menu, &KLikhosherstova::STUDY, study_children_from_mathan, study_children_from_mathan_size
};
const KLikhosherstova::MenuItem KLikhosherstova::GO_BACK = {
    "0 - ����� � ������� ����", KLikhosherstova::go_back, &KLikhosherstova::STUDY
};

namespace {
    const KLikhosherstova::MenuItem* const subject_children[] = {
        &KLikhosherstova::GO_BACK, 
        &KLikhosherstova::STUDY_ALGEBRA,
        &KLikhosherstova::STUDY_MATHAN
    };
    const int subject_size = sizeof(subject_children) / sizeof(subject_children[0]);
}


const KLikhosherstova::MenuItem KLikhosherstova::STUDY = {
    "1 - ���� ������� ����������!", KLikhosherstova::show_menu, &KLikhosherstova::MAIN, subject_children, subject_size
};
const KLikhosherstova::MenuItem KLikhosherstova::EXIT = {
    "0 - �������� ����������!", KLikhosherstova::exit, &KLikhosherstova::MAIN
};

namespace {
    const KLikhosherstova::MenuItem* const main_children[] = {
        &KLikhosherstova::EXIT,
        &KLikhosherstova::STUDY
    };
    const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}

const KLikhosherstova::MenuItem KLikhosherstova::MAIN = {
    nullptr, KLikhosherstova::show_menu, nullptr, main_children, main_size
};
