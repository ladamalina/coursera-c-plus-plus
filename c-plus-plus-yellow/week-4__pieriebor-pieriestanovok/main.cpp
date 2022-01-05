#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> GetDigits(int num) {
    vector<int> digits;
    for (int i=num; i>=1; i--) {
        digits.push_back(i);
    }
    return digits;
}

vector<vector<int>> GetPermutations(const vector<int>& digits) {
    vector<int> permutation = digits;
    vector<vector<int>> permutations;
    do {
        permutations.push_back(permutation);
    } while(prev_permutation(permutation.begin(), permutation.end()));
    return permutations;
}

int main() {
    int num;
    cin >> num;

    vector<int> digits = GetDigits(num);
    vector<vector<int>> permutations = GetPermutations(digits);

    for (auto permutation_it = begin(permutations); permutation_it != end(permutations); ++permutation_it) {
        for (auto digit_it = begin(*permutation_it); digit_it != end(*permutation_it); ++digit_it) {
            cout << *digit_it;
            if (digit_it + 1 == end(*permutation_it)) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
    }
    return 0;
}
