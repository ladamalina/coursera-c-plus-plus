#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>
using namespace std;

template <class T>
class ObjectPool {
public:
  T* Allocate();

  T* TryAllocate();

  void Deallocate(T* object);

  ~ObjectPool();

private:
  set<T*> allocated_;
  queue<T*> deallocated_;
};

template <typename T>
T* ObjectPool<T>::Allocate() {
    if (deallocated_.empty()) {
        deallocated_.push(new T);
    }
    auto ret = deallocated_.front();
    deallocated_.pop();
    allocated_.insert(ret);
    return ret;
}

template <typename T>
T* ObjectPool<T>::TryAllocate() {
    if (deallocated_.empty()) {
        return nullptr;
    }
    return Allocate();
}

template <typename T>
void ObjectPool<T>::Deallocate(T* object) {
    if (allocated_.find(object) == allocated_.end()) {
        throw invalid_argument("");
    }
    allocated_.erase(object);
    deallocated_.push(object);
}

template <typename T>
ObjectPool<T>::~ObjectPool() {
    for (auto x : allocated_) {
        delete x;
    }
    while (!deallocated_.empty()) {
        auto x = deallocated_.front();
        deallocated_.pop();
        delete x;
    }
}

void TestObjectPool() {
  ObjectPool<string> pool;

  auto p1 = pool.Allocate();
  auto p2 = pool.Allocate();
  auto p3 = pool.Allocate();

  *p1 = "first";
  *p2 = "second";
  *p3 = "third";

  pool.Deallocate(p2);
  ASSERT_EQUAL(*pool.Allocate(), "second");

  pool.Deallocate(p3);
  pool.Deallocate(p1);
  ASSERT_EQUAL(*pool.Allocate(), "third");
  ASSERT_EQUAL(*pool.Allocate(), "first");

  pool.Deallocate(p1);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestObjectPool);
  return 0;
}
