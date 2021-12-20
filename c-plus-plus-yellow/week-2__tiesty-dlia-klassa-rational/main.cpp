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

// один из способов вычисления наибольшего общего делителя (НОД) — рекурсивный:
// вместо цикла функция будет вызывать себя же, но с другими аргументами
int GreatestCommonDivisor(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return GreatestCommonDivisor(b, a % b);
    }
}

class Rational {
public:
    Rational() {  // дробь по умолчанию — 0/1
        numerator = 0;
        denominator = 1;
    }
    Rational(int new_numerator, int new_denominator) {
        const int gcd = GreatestCommonDivisor(new_numerator, new_denominator);
        // сократим дробь, разделив числитель и знаменатель на их НОД
        numerator = new_numerator / gcd;
        denominator = new_denominator / gcd;
        // знаменатель должен быть положительным
        if (denominator < 0) {
            denominator = -denominator;
            numerator = -numerator;
        }
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

private:
    int numerator;
    int denominator;
};

void TestDefaultConstructor() {
    Rational r;
    AssertEqual(r.Numerator(), 0);
    AssertEqual(r.Denominator(), 1);
}

void TestNormalization() {
    Rational r{2, 4};
    AssertEqual(r.Numerator(), 1);
    AssertEqual(r.Denominator(), 2);
}

void TestNormalization2() {
    Rational r{2000, 2000};
    AssertEqual(r.Numerator(), 1);
    AssertEqual(r.Denominator(), 1);
}

void TestNormalization3() {
    Rational r{21, 56};
    AssertEqual(r.Numerator(), 3);
    AssertEqual(r.Denominator(), 8);
}

void TestNegativeInvert() {
    Rational r{2, -4};
    AssertEqual(r.Numerator(), -1);
    AssertEqual(r.Denominator(), 2);
}

void TestNegativeToPositive() {
    Rational r{-2, -4};
    AssertEqual(r.Numerator(), 1);
    AssertEqual(r.Denominator(), 2);
}

void TestNegativeToPositive2() {
    Rational r{-4, -2};
    AssertEqual(r.Numerator(), 2);
    AssertEqual(r.Denominator(), 1);
}

void TestZeroNumerator() {
    Rational r{0, -2};
    AssertEqual(r.Numerator(), 0);
    AssertEqual(r.Denominator(), 1);
}

int main() {
    TestRunner runner;
    runner.RunTest(TestDefaultConstructor, "TestDefaultConstructor");
    runner.RunTest(TestNormalization, "TestNormalization");
    runner.RunTest(TestNormalization2, "TestNormalization2");
    runner.RunTest(TestNormalization3, "TestNormalization3");
    runner.RunTest(TestNegativeInvert, "TestNegativeInvert");
    runner.RunTest(TestNegativeToPositive, "TestNegativeToPositive");
    runner.RunTest(TestNegativeToPositive2, "TestNegativeToPositive2");
    runner.RunTest(TestZeroNumerator, "TestZeroNumerator");
    return 0;
}
