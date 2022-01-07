#include <string>
#include "test_runner.h"
#include "deque.h"
using namespace std;

void TestEmpty() {
    Deque<int> d;
    ASSERT(d.Empty());
    ASSERT_EQUAL(d.Size(), 0);
}

void TestOneFront() {
    Deque<int> d;
    d.PushFront(0);
    ASSERT_EQUAL(d.Size(), 1);
    ASSERT_EQUAL(d.Front(), 0);
    ASSERT_EQUAL(d.Back(), 0);
    ASSERT_EQUAL(d.At(0), 0);
    ASSERT_EQUAL(d[0], 0);
}

void TestOneBack() {
    Deque<int> d;
    d.PushBack(0);
    ASSERT_EQUAL(d.Size(), 1);
    ASSERT_EQUAL(d.Front(), 0);
    ASSERT_EQUAL(d.Back(), 0);
    ASSERT_EQUAL(d.At(0), 0);
    ASSERT_EQUAL(d[0], 0);
}

void TestFrontAndBack() {
    Deque<int> d;
    d.PushFront(0);
    d.PushFront(1);
    d.PushFront(2);
    d.PushFront(3);
    d.PushBack(0);
    d.PushBack(1);
    d.PushBack(2);
    ASSERT_EQUAL(d.Size(), 7);
    ASSERT_EQUAL(d.Front(), 3);
    ASSERT_EQUAL(d.Back(), 2);
    ASSERT_EQUAL(d.At(0), 3);
    ASSERT_EQUAL(d.At(2), 1);
    ASSERT_EQUAL(d.At(5), 1);
    ASSERT_EQUAL(d.At(6), 2);
    ASSERT_EQUAL(d[0], 3);
    ASSERT_EQUAL(d[5], 1);
}

void TestTailOnly() {
    Deque<int> d;
    d.PushBack(0);
    d.PushBack(1);
    d.PushBack(2);
    ASSERT_EQUAL(d.Size(), 3);
    ASSERT_EQUAL(d.Front(), 0);
    ASSERT_EQUAL(d.Back(), 2);
    ASSERT_EQUAL(d.At(0), 0);
    ASSERT_EQUAL(d.At(2), 2);
    ASSERT_EQUAL(d[0], 0);
    ASSERT_EQUAL(d[2], 2);
}

void TestString() {
    Deque<string> d;
    d.PushFront("0");
    d.PushFront("1");
    d.PushFront("2");
    d.PushFront("3");
    d.PushBack("0");
    d.PushBack("1");
    d.PushBack("2");
    ASSERT_EQUAL(d.Size(), 7);
    ASSERT_EQUAL(d.Front(), "3");
    ASSERT_EQUAL(d.Back(), "2");
    ASSERT_EQUAL(d.At(0), "3");
    ASSERT_EQUAL(d.At(2), "1");
    ASSERT_EQUAL(d.At(5), "1");
    ASSERT_EQUAL(d.At(6), "2");
    ASSERT_EQUAL(d[0], "3");
    ASSERT_EQUAL(d[5], "1");

    const string const_str = d[5];
    ASSERT_EQUAL(const_str, "1");

    string mutable_str = d[5];
    ASSERT_EQUAL(mutable_str, "1");
}

void TestAll() {
    TestRunner tr;
    RUN_TEST(tr, TestEmpty);
    RUN_TEST(tr, TestOneFront);
    RUN_TEST(tr, TestOneBack);
    RUN_TEST(tr, TestFrontAndBack);
    RUN_TEST(tr, TestTailOnly);
    RUN_TEST(tr, TestString);
}

int main() {
    TestAll();
    return 0;
}
