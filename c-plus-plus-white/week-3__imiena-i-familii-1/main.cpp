/*
 * Реализуйте класс для человека, поддерживающий историю изменений человеком своих фамилии и имени.
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        // добавить факт изменения имени на first_name в год year
        if (years.count(year) == 0) {
            years[year] = {first_name, ""};
        } else {
            years[year][0] = first_name;
        }
    }
    void ChangeLastName(int year, const string& last_name) {
        // добавить факт изменения фамилии на last_name в год year
        if (years.count(year) == 0) {
            years[year] = {"", last_name};
        } else {
            years[year][1] = last_name;
        }
    }
    string GetFullName(int year) {
        // получить имя и фамилию по состоянию на конец года year
        string firstName;
        string lastName;

        if (years.count(year) == 0) {
            firstName = getLastRecordBefore(year, 0);
            lastName = getLastRecordBefore(year, 1);
        } else { // years.count(year) == 1
            firstName = years[year][0];
            if (firstName.length() == 0) {
                firstName = getLastRecordBefore(year, 0);
            }

            lastName = years[year][1];
            if (lastName.length() == 0) {
                lastName = getLastRecordBefore(year, 1);
            }
        }

        if (firstName.length() && lastName.length()) {
            return firstName + ' ' + lastName;
        } else if (firstName.length()) {
            return firstName + " with unknown last name";
        } else if (lastName.length()) {
            return lastName + " with unknown first name";
        } else {
            return "Incognito";
        }
    }
private:
    // приватные поля
    map<int, vector<string>> years;
    string getLastRecordBefore(int year, int idx) {
        vector<string> lastRecordBefore = {"", ""};
        for (const auto& item : years) {
            if (item.first < year && item.second[idx].length()) {
                lastRecordBefore = item.second;
            }
        }
        return lastRecordBefore[idx];
    }
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}
