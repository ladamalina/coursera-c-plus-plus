/*
 * Дана структура LectureTitle. Допишите конструктор и структуры Specialization, Course, Week так,
 * чтобы объект LectureTitle можно было создать с помощью кода:
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

struct Specialization {
    string str;
    explicit Specialization(const string& new_str) {
        str = new_str;
    }
};

struct Course {
    string str;
    explicit Course(const string& new_str) {
        str = new_str;
    }
};

struct Week {
    string str;
    explicit Week(const string& new_str) {
        str = new_str;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;
    explicit LectureTitle(const Specialization& new_specialization,
                          const Course& new_course,
                          const Week& new_week) {
        specialization = new_specialization.str;
        course = new_course.str;
        week = new_week.str;
    }
};

int main() {
    LectureTitle title(
        Specialization("C++"),
        Course("White belt"),
        Week("4th")
    );
    return 0;
}
