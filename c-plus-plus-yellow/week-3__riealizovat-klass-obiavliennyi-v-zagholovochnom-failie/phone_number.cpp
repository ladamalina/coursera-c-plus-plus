#include <stdexcept>
#include <string>
#include <tuple>
#include "phone_number.h"

using namespace std;

tuple<string, int> ParseCode(const string& number, size_t begin_idx) {
    size_t len = number.length();
    size_t end_idx = -1;
    string code;
    for (size_t i=begin_idx; i<len; i++) {
        if (number[i] != '-') {
            code.push_back(number[i]);
            end_idx = i+1;
        } else {
            end_idx = i;
            break;
        }
    }

    return make_tuple(code, end_idx);
}

PhoneNumber::PhoneNumber(const string& international_number) {
    size_t len = international_number.length();
    if (len < 6) {
        throw invalid_argument("некорректный номер - длина меньше 6 символов");
    }
    if (international_number[0] != '+') {
        throw invalid_argument("некорректный номер - не начинается на '+' (" + international_number + ")");
    }

    size_t country_city_delimiter_idx = -1;
    tie(country_code_, country_city_delimiter_idx) = ParseCode(international_number, 1);
    if (country_code_.length() == 0) {
        throw invalid_argument("некорректный номер - нет кода страны");
    }

    size_t city_local_delimiter_idx = -1;
    tie(city_code_, city_local_delimiter_idx) =
            ParseCode(international_number, country_city_delimiter_idx+1);
    if (city_code_.length() == 0) {
        throw invalid_argument("некорректный номер - нет кода города");
    }

    for (size_t i=city_local_delimiter_idx+1; i<len; i++) {
        local_number_.push_back(international_number[i]);
    }
    if (local_number_.length() == 0) {
        throw invalid_argument("некорректный номер - нет местного номера");
    }
}

string PhoneNumber::GetCountryCode() const {
    return country_code_;
}

string PhoneNumber::GetCityCode() const {
    return city_code_;
}

string PhoneNumber::GetLocalNumber() const {
    return local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
    return "+"+country_code_+"-"+city_code_+"-"+local_number_;
}
