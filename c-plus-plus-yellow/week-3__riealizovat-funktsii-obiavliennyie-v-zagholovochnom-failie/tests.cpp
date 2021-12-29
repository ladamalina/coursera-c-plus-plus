#include "test_runner.h"
#include "sum_reverse_sort.h"

using namespace std;

void TestSum() {
    AssertEqual(Sum(1, 2), 3);
    AssertEqual(Sum(0, 2), 2);
    AssertEqual(Sum(-1, 2), 1);
    AssertEqual(Sum(-3, 2), -1);
    AssertEqual(Sum(-3, -2), -5);
}

void TestReverse() {
    AssertEqual(Reverse(""), "");
    AssertEqual(Reverse("a"), "a");
    AssertEqual(Reverse("ab"), "ba");
    AssertEqual(Reverse("abc"), "cba");
    AssertEqual(Reverse("abcd"), "dcba");
    AssertEqual(Reverse(" abcd"), "dcba ");
    AssertEqual(Reverse("abcd "), " dcba");
}

void TestSort() {
    vector<int> nums = {};
    Sort(nums);
    vector<int> expected = {};
    AssertEqual(nums, expected);

    vector<int> nums2 = {1};
    Sort(nums2);
    vector<int> expected2 = {1};
    AssertEqual(nums2, expected2);

    vector<int> nums3 = {2, 1};
    Sort(nums3);
    vector<int> expected3 = {1, 2};
    AssertEqual(nums3, expected3);

    vector<int> nums4 = {1, -1, 2};
    Sort(nums4);
    vector<int> expected4 = {-1, 1, 2};
    AssertEqual(nums4, expected4);
}

void TestAll() {
    TestRunner runner;
    runner.RunTest(TestSum, "TestSum");
    runner.RunTest(TestReverse, "TestReverse");
    runner.RunTest(TestSort, "TestSort");
}
