/*
 * Реализуйте шаблонную функцию GetRefStrict, которая на вход принимает: map и значение ключа k.
 * Если элемент по ключу k в коллекции отсутствует, то функция должна бросить исключение runtime_error,
 * иначе вернуть ссылку на элемент в коллекции.
 */

#include <map>
#include <stdexcept>
using namespace std;

template<typename KeyType, typename ValueType>
ValueType& GetRefStrict(map<KeyType, ValueType>& input_map, KeyType key) {
    if (input_map.count(key) == 0) {
        throw runtime_error("no such key in dictionary");
    }
    return input_map[key];
}
