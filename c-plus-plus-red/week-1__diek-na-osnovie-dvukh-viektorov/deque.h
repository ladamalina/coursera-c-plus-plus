#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

template <typename T>
class Deque {
public:
    // конструктор по умолчанию
    Deque() {
        head_ = {};
        tail_ = {};
    }

    // константный метод Empty, возвращающий true, если дек не содержит ни одного элемента
    bool Empty() const {
        return Size() == 0;
    }

    // константный метод Size, возвращающий количество элементов в деке
    size_t Size() const {
        return head_.size() + tail_.size();
    }

    T& operator[](size_t index) {
        return const_cast<T&>(const_cast<const Deque*>(this)->At(index));
    }

    const T& operator[](size_t index) const {
        const T& value = At(index);
        return value;
    }

    // константный и неконстантный метод At(size_t index), генерирующий стандартное исключение out_of_range,
    // если индекс больше или равен количеству элементов в деке
    T& At(size_t index) {
        return const_cast<T&>(const_cast<const Deque*>(this)->At(index));
    }

    const T& At(size_t index) const {
        if (index >= Size()) {
            throw out_of_range("Index " + to_string(index) + " is out of range " + to_string(Size()));
        }
        if (index < head_.size()) {
            // [2,1,0][0,1,2,3] index=2
            return head_[head_.size() - index - 1];
        }
        size_t tail_index = index - head_.size();
        // [2,1,0][0,1,2,3] index=6, size_=7, head_size_=4, tail_size_=3
        return tail_[tail_index];
    }

    // константные и неконстантные версии методов Front и Back, возвращающих ссылки
    // на первый и последний элемент дека соответственно
    T& Front() {
        return const_cast<T&>(const_cast<const Deque*>(this)->Front());
    }

    const T& Front() const {
        const T& value = At(0);
        return value;
    }

    T& Back() {
        return const_cast<T&>(const_cast<const Deque*>(this)->Back());
    }

    const T& Back() const {
        const T& value = At(Size()-1);
        return value;
    }

    void PushFront(const T& item) {
        head_.push_back(item);
    }
    void PushBack(const T& item) {
        tail_.push_back(item);
    }

private:
    vector<T> head_;
    vector<T> tail_;
};
