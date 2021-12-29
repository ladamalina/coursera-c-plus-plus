#include <algorithm>
#include <vector>
#include "sum_reverse_sort.h"

using namespace std;

int Sum(int x, int y) {
    return x + y;
};

string Reverse(string s) {
    int n = s.length();
    string rev;
    for (int i=n-1; i>=0; i--) {
        rev.push_back(s[i]);
    }
    return rev;
}

void Sort(vector<int>& nums) {
    return sort(nums.begin(), nums.end());
}