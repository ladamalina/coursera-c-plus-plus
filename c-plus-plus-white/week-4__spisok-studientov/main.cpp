/*
 * Определите структуру «Студент» со следующими полями: имя, фамилия, день, месяц и год рождения.
 * Создайте вектор из таких структур, заполните его из входных данных и затем по запросам выведите нужные поля.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student {
    string firstName;
    string lastName;
    int yearOfBirth = 0;
    int monthOfBirth = 0;
    int dayOfBirth = 0;
};

int main() {
    int n;
    cin >> n;

    string firstName, lastName;
    int day, month, year;
    vector<Student> students;
    for (int i = 0; i < n; ++i) {
        cin >> firstName >> lastName >> day >> month >> year;
        students.push_back(Student{firstName, lastName, year, month, day});
    }

    int m;
    cin >> m;
    string query;
    int studentNum;
    for (int i = 0; i < m; ++i) {
        cin >> query >> studentNum;
        --studentNum;

        if (query == "name" && studentNum >= 0 && studentNum < n) {
            cout << students[studentNum].firstName << " "
                 << students[studentNum].lastName << endl;
        } else if (query == "date" && studentNum >= 0 && studentNum < n) {
            cout << students[studentNum].dayOfBirth << "."
                 << students[studentNum].monthOfBirth << "."
                 << students[studentNum].yearOfBirth << endl;
        } else {
            cout << "bad request" << endl;
        }
    }

    return 0;
}
