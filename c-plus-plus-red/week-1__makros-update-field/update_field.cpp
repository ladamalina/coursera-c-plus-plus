#include "airline_ticket.h"
#include "test_runner.h"

#include <iomanip>
#include <iostream>
#include <iterator>
#include <sstream>

using namespace std;

bool operator< (const Date& l, const Date& r) {
    return tie(l.year, l.month, l.day) < tie(r.year, r.month, r.day);
}

bool operator== (const Date& l, const Date& r) {
    return tie(l.year, l.month, l.day) == tie(r.year, r.month, r.day);
}

ostream& operator<< (ostream& stream, const Date& d) {
    stream << setw(4) << setfill('0') << d.year <<
           "-" << setw(2) << setfill('0') << d.month <<
           "-" << setw(2) << setfill('0') << d.day;
    return stream;
}

istream& operator>> (istream& in, Date& d) {
    string d_year_str;
    getline(in, d_year_str, '-');
    d.year = stoi(d_year_str);

    string d_month_str;
    getline(in, d_month_str, '-');
    d.month = stoi(d_month_str);

    in >> d.day;

    return in;
}

bool operator< (const Time& l, const Time& r) {
    return tie(l.hours, l.minutes) < tie(r.hours, r.minutes);
}

bool operator== (const Time& l, const Time& r) {
    return tie(l.hours, l.minutes) == tie(r.hours, r.minutes);
}

ostream& operator<< (ostream& stream, const Time& t) {
    stream << setw(2) << setfill('0') << t.hours <<
           "-" << setw(2) << setfill('0') << t.minutes;
    return stream;
}

istream& operator>> (istream& in, Time& t) {
    string t_hour_str;
    getline(in, t_hour_str, ':');
    t.hours = stoi(t_hour_str);

    in >> t.minutes;

    return in;
}

#define UPDATE_FIELD(ticket, field, values) [&ticket, &values] { \
    auto it = values.find(#field);                               \
    if (it != values.end()) {                                    \
        istringstream is(it->second);                            \
        is >> ticket.field;                                      \
    }                                                            \
}()

void TestUpdate() {
  AirlineTicket t;
  t.price = 0;

  const map<string, string> updates1 = {
    {"departure_date", "2018-2-28"},
    {"departure_time", "17:40"},
  };
  UPDATE_FIELD(t, departure_date, updates1);
  UPDATE_FIELD(t, departure_time, updates1);
  UPDATE_FIELD(t, price, updates1);

  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 0);

  const map<string, string> updates2 = {
    {"price", "12550"},
    {"arrival_time", "20:33"},
  };
  UPDATE_FIELD(t, departure_date, updates2);
  UPDATE_FIELD(t, departure_time, updates2);
  UPDATE_FIELD(t, arrival_time, updates2);
  UPDATE_FIELD(t, price, updates2);

  // updates2 не содержит ключей "departure_date" и "departure_time", поэтому
  // значения этих полей не должны измениться
  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 12550);
  ASSERT_EQUAL(t.arrival_time, (Time{20, 33}));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestUpdate);
}
