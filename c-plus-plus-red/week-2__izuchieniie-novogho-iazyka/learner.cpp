#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <sstream>
#include <vector>

#include "profile.h"

using namespace std;

class Learner {
private:
  set<string> unique_dict_;

public:
  int Learn(const vector<string>& words) {
    size_t dict_size_before = unique_dict_.size();
    unique_dict_.insert(words.begin(), words.end());
    size_t dict_size_after = unique_dict_.size();
    size_t words_learned = dict_size_after - dict_size_before;

    return words_learned;
  }

  vector<string> KnownWords() {
    return vector(unique_dict_.begin(), unique_dict_.end());
  }
};

int main() {
    Learner learner;
    string line;
    {
        LOG_DURATION("Duration Learn")
        while (getline(cin, line)) {
            vector<string> words;
            stringstream ss(line);
            string word;
            while (ss >> word) {
                words.push_back(word);
            }
            cout << learner.Learn(words) << "\n";
        }
    }
    cout << "=== known words ===\n";
    {
        LOG_DURATION("Duration KnownWords")
        for (auto word : learner.KnownWords()) {
            cout << word << "\n";
        }
    }
}
