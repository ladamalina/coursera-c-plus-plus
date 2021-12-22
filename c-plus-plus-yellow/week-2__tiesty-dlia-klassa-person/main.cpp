#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        } catch (exception& e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        } catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

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
            if (item.first <= year && item.second[idx].length()) {
                lastRecordBefore = item.second;
            }
        }
        return lastRecordBefore[idx];
    }
};

void TestIncognitoInitial() {
    Person p;
    AssertEqual(p.GetFullName(2000), "Incognito");
}

void TestIncognitoBeforeBirth() {
    Person p;
    p.ChangeFirstName(2001, "FirstName");
    AssertEqual(p.GetFullName(2000), "Incognito");
}

void TestInitFirstNameThisYear() {
    Person p;
    p.ChangeFirstName(2000, "FirstName");
    AssertEqual(p.GetFullName(2000), "FirstName with unknown last name");
}

void TestInitFirstNameLastYear() {
    Person p;
    p.ChangeFirstName(2000, "FirstName");
    AssertEqual(p.GetFullName(2001), "FirstName with unknown last name");
}

void TestChangedFirstNameTwiceA() {
    Person p;
    p.ChangeFirstName(1998, "FirstName A");
    p.ChangeFirstName(2000, "FirstName B");
    AssertEqual(p.GetFullName(2001), "FirstName B with unknown last name");
}

void TestChangedFirstNameTwiceB() {
    Person p;
    p.ChangeFirstName(2000, "FirstName B");
    p.ChangeFirstName(1998, "FirstName A");
    AssertEqual(p.GetFullName(2001), "FirstName B with unknown last name");
}

void TestChangedFirstNameTwiceC() {
    Person p;
    p.ChangeFirstName(2000, "FirstName B");
    p.ChangeFirstName(1998, "FirstName A");
    AssertEqual(p.GetFullName(1998), "FirstName A with unknown last name");
}

void TestInitLastNameThisYear() {
    Person p;
    p.ChangeLastName(2000, "LastName");
    AssertEqual(p.GetFullName(2000), "LastName with unknown first name");
}

void TestInitLastNameLastYear() {
    Person p;
    p.ChangeLastName(2000, "LastName");
    AssertEqual(p.GetFullName(2001), "LastName with unknown first name");
}

void TestChangedNamesAFewTimes() {
    Person p;
    p.ChangeFirstName(1990, "FirstName A");
    p.ChangeLastName(1991, "LastName A");
    p.ChangeFirstName(1997, "FirstName B");
    p.ChangeLastName(1999, "LastName B");
    AssertEqual(p.GetFullName(1996), "FirstName A LastName A");
    AssertEqual(p.GetFullName(1998), "FirstName B LastName A");
    AssertEqual(p.GetFullName(2000), "FirstName B LastName B");
}

int main() {
    TestRunner runner;
    runner.RunTest(TestIncognitoInitial, "TestIncognitoInitial");
    runner.RunTest(TestIncognitoBeforeBirth, "TestIncognitoBeforeBirth");
    runner.RunTest(TestInitFirstNameThisYear, "TestInitFirstNameThisYear");
    runner.RunTest(TestInitFirstNameLastYear, "TestInitFirstNameLastYear");
    runner.RunTest(TestChangedFirstNameTwiceA, "TestChangedFirstNameTwiceA");
    runner.RunTest(TestChangedFirstNameTwiceB, "TestChangedFirstNameTwiceB");
    runner.RunTest(TestChangedFirstNameTwiceC, "TestChangedFirstNameTwiceC");
    runner.RunTest(TestInitLastNameThisYear, "TestInitLastNameThisYear");
    runner.RunTest(TestInitLastNameLastYear, "TestInitLastNameLastYear");
    runner.RunTest(TestChangedNamesAFewTimes, "TestChangedNamesAFewTimes");
    return 0;
}
