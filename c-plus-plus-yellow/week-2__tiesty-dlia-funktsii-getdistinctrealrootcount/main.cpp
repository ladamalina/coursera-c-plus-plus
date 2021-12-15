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
        cerr << "........................................" << endl;
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
        cerr << "........................................" << endl;
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

int GetDistinctRealRootCount(double a, double b, double c) {
    // Вы можете вставлять сюда различные реализации функции,
    // чтобы проверить, что ваши тесты пропускают корректный код
    // и ловят некорректный
}

void TestDistinctRealRootCount(double a, double b, double c, int expected) {
    int actual = GetDistinctRealRootCount(a, b, c);
    cerr << "a=" << a << ", b=" << b << ", c=" << c << endl;
    cerr << "expected=" << expected << ", actual=" << actual << endl;
    AssertEqual(actual, expected);
}

void TestEqualRoots() {
    double a = 9;
    double b = 12;
    double c = 4;
    int expected = 1;
    TestDistinctRealRootCount(a, b, c, expected);
}

void TestDistinctRoots() {
    double a = 2;
    double b = 3;
    double c = -11;
    int expected = 2;
    TestDistinctRealRootCount(a, b, c, expected);
}

void TestNoRootsNegativeD() {
    double a = 1;
    double b = 1;
    double c = 1;
    int expected = 0;
    TestDistinctRealRootCount(a, b, c, expected);
}

void TestNoRootsInvalid() {
    double a = 0;
    double b = 0;
    double c = 1;
    int expected = 0;
    TestDistinctRealRootCount(a, b, c, expected);
}

int main() {
    TestRunner runner;
    runner.RunTest(TestEqualRoots, "TestEqualRoots");
    runner.RunTest(TestDistinctRoots, "TestDistinctRoots");
    runner.RunTest(TestNoRootsNegativeD, "TestNoRootsNegativeD");
    runner.RunTest(TestNoRootsInvalid, "TestNoRootsInvalid");
    return 0;
}
