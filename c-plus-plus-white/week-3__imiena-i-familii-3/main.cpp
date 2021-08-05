/*
 * Дополните класс Person из задачи «Имена и фамилии — 2» конструктором, позволяющим задать
 * имя и фамилию человека при рождении, а также сам год рождения. Класс не должен иметь конструктора по умолчанию.
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Person {
public:
    Person(const string& firstName, const string& lastName, const int& yearOfBirth) {
        initYearOfBirth = yearOfBirth;
        ChangeFirstName(initYearOfBirth, firstName);
        ChangeLastName(initYearOfBirth, lastName);
    }

    void ChangeFirstName(int year, const string& first_name) {
        if (year < initYearOfBirth) {
            return;
        }
        // добавить факт изменения имени на first_name в год year
        if (years.count(year) == 0) {
            years[year] = {first_name, ""};
        } else {
            years[year][0] = first_name;
        }
    }

    void ChangeLastName(int year, const string& last_name) {
        if (year < initYearOfBirth) {
            return;
        }
        // добавить факт изменения фамилии на last_name в год year
        if (years.count(year) == 0) {
            years[year] = {"", last_name};
        } else {
            years[year][1] = last_name;
        }
    }

    string GetFullName(int year) const {
        if (year < initYearOfBirth) {
            return "No person";
        }

        // получить имя и фамилию по состоянию на конец года year
        string firstName;
        string lastName;

        if (years.count(year) == 0) {
            firstName = getLastRecordBefore(year, 0);
            lastName = getLastRecordBefore(year, 1);
        } else { // years.count(year) == 1
            firstName = years.at(year)[0];
            if (firstName.length() == 0) {
                firstName = getLastRecordBefore(year, 0);
            }

            lastName = years.at(year)[1];
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

    string GetFullNameWithHistory(int year) const {
        if (year < initYearOfBirth) {
            return "No person";
        }

        // получить все имена и фамилии по состоянию на конец года year
        vector<string> firstNameHistory = getHistoryRecords(year, 0);
        vector<string> lastNameHistory = getHistoryRecords(year, 1);

        string firstName = firstNameHistory.empty() ? "" : firstNameHistory[firstNameHistory.size()-1];
        string lastName = lastNameHistory.empty() ? "" : lastNameHistory[lastNameHistory.size()-1];

        string firstNameHistoryStr = joinHistoryRecords(firstNameHistory);
        string lastNameHistoryStr = joinHistoryRecords(lastNameHistory);

        if (firstName.length() && lastName.length()) {
            return firstName + (firstNameHistoryStr.length() ? (" " + firstNameHistoryStr) : "")
            + " " + lastName + (lastNameHistoryStr.length() ? (" " + lastNameHistoryStr) : "");
        } else if (firstName.length()) {
            return firstName + (firstNameHistoryStr.length() ? (" " + firstNameHistoryStr) : "")
            + " with unknown last name";
        } else if (lastName.length()) {
            return lastName + (lastNameHistoryStr.length() ? (" " + lastNameHistoryStr) : "")
            + " with unknown first name";
        } else {
            return "Incognito";
        }
    }
private:
    // приватные поля
    map<int, vector<string>> years;
    int initYearOfBirth = 0;

    string getLastRecordBefore(int year, int idx) const {
        vector<string> lastRecordBefore = {"", ""};
        for (const auto& item : years) {
            if (item.first < year && item.second[idx].length()) {
                lastRecordBefore = item.second;
            }
        }
        return lastRecordBefore[idx];
    }

    vector<string> getHistoryRecords(int year, int idx) const {
        vector<string> historyRecords = {};
        for (const auto& item : years) {
            if (item.first <= year && item.second[idx].length()) {
                historyRecords.push_back(item.second[idx]);
            }
        }
        deduplicateRecords(historyRecords);
        return historyRecords;
    }

    void deduplicateRecords(vector<string>& records) const {
        for (int i = records.size()-1; i > 0; --i) {
            if (records[i] == records[i-1]) {
                records.erase(records.begin() + i);
            }
        }
    }

    string joinHistoryRecords(const vector<string>& records) const {
        string recordsStr;
        if (records.size() > 1) {
            recordsStr += records[records.size()-2];
            for (int i = records.size()-3; i >=0; --i) {
                recordsStr += ", ";
                recordsStr += records[i];
            }
            recordsStr = "(" + recordsStr + ")";
        }

        return recordsStr;
    }
};

int main() {
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}
