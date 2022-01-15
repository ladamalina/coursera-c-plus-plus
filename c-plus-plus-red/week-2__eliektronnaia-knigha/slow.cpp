#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <utility>

#include "profile.h"

using namespace std;

class ReadingManager {
public:
  ReadingManager() {}

  void Read(int user_id, int page_count) {
    if (user_page_.count(user_id) == 0) {
      AddUser(user_id);
    }
    int page_count_before = user_page_[user_id];
    user_page_[user_id] = page_count;

    if (pages_.count(page_count) == 0) {
        pages_.insert(page_count);
    }
    if (page_to_users_.count(page_count) == 0) {
        set<int> new_page_set;
        page_to_users_[page_count] = new_page_set;
    }
    page_to_users_[page_count].insert(user_id);

    page_to_users_[page_count_before].erase(user_id);
    if (page_to_users_[page_count_before].empty()) {
        page_to_users_.erase(page_count_before);
        pages_.erase(page_count_before);
    }
  }

  double Cheer(int user_id) const {
    if (user_page_.count(user_id) == 0) {
      return 0;
    }
    if (user_page_.at(user_id) == DEFAULT_PAGES_COUNT_) {
      return 0;
    }
    const int user_count = GetUserCount();
    if (user_count == 1) {
      return 1;
    }

    const int page_count = user_page_.at(user_id);

    auto lower_it = pages_.lower_bound(page_count);
    int users_count = 0;
    for (auto it = pages_.begin(); it != lower_it; ++it) {
        if (*it >= page_count) {
            break;
        }
        users_count += page_to_users_.at(*it).size();
    }

    // По умолчанию деление целочисленное, поэтому
    // нужно привести числитель к типу double.
    // Простой способ сделать это — умножить его на 1.0.
    return users_count * 1.0 / (user_count - 1);
  }

private:
  const int DEFAULT_PAGES_COUNT_ = -1;
  map<int, int> user_page_;
  set<int> pages_;
  map<int, set<int>> page_to_users_;

  int GetUserCount() const {
    return user_page_.size();
  }
  void AddUser(int user_id) {
    user_page_[user_id] = DEFAULT_PAGES_COUNT_;
  }
};


int main() {
  // Для ускорения чтения данных отключается синхронизация
  // cin и cout с stdio,
  // а также выполняется отвязка cin от cout
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ReadingManager manager;

  int query_count;
  cin >> query_count;

  {
    LOG_DURATION("Total")
    for (int query_id = 0; query_id < query_count; ++query_id) {
      string query_type;
      cin >> query_type;
      int user_id;
      cin >> user_id;

      if (query_type == "READ") {
          int page_count;
          cin >> page_count;
          manager.Read(user_id, page_count);
      } else if (query_type == "CHEER") {
          cout << setprecision(6) << manager.Cheer(user_id) << "\n";
      }
    }
  }

  return 0;
}