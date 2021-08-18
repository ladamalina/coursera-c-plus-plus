/*
 * Дополните класс из предыдущей задачи «Имена и фамилии — 1» методом GetFullNameWithHistory
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

    string GetFullNameWithHistory(int year) {
        // получить все имена и фамилии по состоянию на конец года year
        vector<string> firstNameHistory = getHistoryRecords(year, 0);
        vector<string> lastNameHistory = getHistoryRecords(year, 1);

        string firstName = firstNameHistory.size() ? firstNameHistory[firstNameHistory.size()-1] : "";
        string lastName = lastNameHistory.size() ? lastNameHistory[lastNameHistory.size()-1] : "";

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

    string getLastRecordBefore(int year, int idx) {
        vector<string> lastRecordBefore = {"", ""};
        for (const auto& item : years) {
            if (item.first < year && item.second[idx].length()) {
                lastRecordBefore = item.second;
            }
        }
        return lastRecordBefore[idx];
    }

    vector<string> getHistoryRecords(int year, int idx) {
        vector<string> historyRecords = {};
        for (const auto& item : years) {
            if (item.first <= year && item.second[idx].length()) {
                historyRecords.push_back(item.second[idx]);
            }
        }
        deduplicateRcords(historyRecords);
        return historyRecords;
    }

    void deduplicateRcords(vector<string>& records) {
        for (int i = records.size()-1; i > 0; --i) {
            if (records[i] == records[i-1]) {
                records.erase(records.begin() + i);
            }
        }
    }

    string joinHistoryRecords(const vector<string>& records) {
        string recordsStr = "";
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
    Person person;

    person.ChangeFirstName(1900, "Eugene");
    person.ChangeLastName(1900, "Sokolov");
    person.ChangeLastName(1910, "Sokolov");
    person.ChangeFirstName(1920, "Evgeny");
    person.ChangeLastName(1930, "Sokolov");
    cout << person.GetFullNameWithHistory(1940) << endl;

    return 0;
}
