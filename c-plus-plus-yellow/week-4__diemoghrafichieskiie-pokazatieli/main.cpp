#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

enum class Gender {
    FEMALE,
    MALE
};

struct Person {
    int age;  // возраст
    Gender gender;  // пол
    bool is_employed;  // имеет ли работу
};

// Это пример функции, его не нужно отправлять вместе с функцией PrintStats
template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
    if (range_begin == range_end) {
        return 0;
    }
    vector<typename InputIt::value_type> range_copy(range_begin, range_end);
    auto middle = begin(range_copy) + range_copy.size() / 2;
    nth_element(
            begin(range_copy), middle, end(range_copy),
            [](const Person& lhs, const Person& rhs) {
                return lhs.age < rhs.age;
            }
    );
    return middle->age;
}

void PrintStats(vector<Person> persons) {
    int median_age = ComputeMedianAge(begin(persons), end(persons));
    cout << "Median age = " << median_age << endl;

    vector<Person> females;
    copy_if(begin(persons), end(persons), back_inserter(females),
            [](Person p){return p.gender == Gender::FEMALE;} );
    int median_age_females = ComputeMedianAge(begin(females), end(females));
    cout << "Median age for females = " << median_age_females << endl;

    vector<Person> males;
    copy_if(begin(persons), end(persons), back_inserter(males),
            [](Person p){return p.gender == Gender::MALE;} );
    int median_age_males = ComputeMedianAge(begin(males), end(males));
    cout << "Median age for males = " << median_age_males << endl;

    vector<Person> employed_females;
    copy_if(begin(females), end(females), back_inserter(employed_females),
            [](Person p){return p.is_employed;} );
    int median_age_employed_females = ComputeMedianAge(begin(employed_females), end(employed_females));
    cout << "Median age for employed females = " << median_age_employed_females << endl;

    vector<Person> unemployed_females;
    copy_if(begin(females), end(females), back_inserter(unemployed_females),
            [](Person p){return !p.is_employed;} );
    int median_age_unemployed_females = ComputeMedianAge(begin(unemployed_females), end(unemployed_females));
    cout << "Median age for unemployed females = " << median_age_unemployed_females << endl;

    vector<Person> employed_males;
    copy_if(begin(males), end(males), back_inserter(employed_males),
            [](Person p){return p.is_employed;} );
    int median_age_employed_males = ComputeMedianAge(begin(employed_males), end(employed_males));
    cout << "Median age for employed males = " << median_age_employed_males << endl;

    vector<Person> unemployed_males;
    copy_if(begin(males), end(males), back_inserter(unemployed_males),
            [](Person p){return !p.is_employed;} );
    int median_age_unemployed_males = ComputeMedianAge(begin(unemployed_males), end(unemployed_males));
    cout << "Median age for unemployed males = " << median_age_unemployed_males << endl;
}

int main() {
    vector<Person> persons = {
        {31, Gender::MALE, false},
        {40, Gender::FEMALE, true},
        {24, Gender::MALE, true},
        {20, Gender::FEMALE, true},
        {80, Gender::FEMALE, false},
        {78, Gender::MALE, false},
        {10, Gender::FEMALE, false},
        {55, Gender::MALE, true},
    };
    PrintStats(persons);
    return 0;
}
