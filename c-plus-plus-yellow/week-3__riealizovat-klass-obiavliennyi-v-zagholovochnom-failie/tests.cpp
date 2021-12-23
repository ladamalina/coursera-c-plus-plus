#include "test_runner.h"
#include "phone_number.h"

using namespace std;

void TestPhoneNumber1() {
    PhoneNumber pn{"+7-495-111-22-33"};
    AssertEqual(pn.GetCountryCode(), "7");
    AssertEqual(pn.GetCityCode(), "495");
    AssertEqual(pn.GetLocalNumber(), "111-22-33");
    AssertEqual(pn.GetInternationalNumber(), "+7-495-111-22-33");
}
void TestPhoneNumber2() {
    PhoneNumber pn{"+7-495-1112233"};
    AssertEqual(pn.GetCountryCode(), "7");
    AssertEqual(pn.GetCityCode(), "495");
    AssertEqual(pn.GetLocalNumber(), "1112233");
    AssertEqual(pn.GetInternationalNumber(), "+7-495-1112233");
}
void TestPhoneNumber3() {
    PhoneNumber pn{"+7-495-1112233-"};
    AssertEqual(pn.GetCountryCode(), "7");
    AssertEqual(pn.GetCityCode(), "495");
    AssertEqual(pn.GetLocalNumber(), "1112233-");
    AssertEqual(pn.GetInternationalNumber(), "+7-495-1112233-");
}
void TestPhoneNumber4() {
    PhoneNumber pn{"+323-22-460002"};
    AssertEqual(pn.GetCountryCode(), "323");
    AssertEqual(pn.GetCityCode(), "22");
    AssertEqual(pn.GetLocalNumber(), "460002");
    AssertEqual(pn.GetInternationalNumber(), "+323-22-460002");
}
void TestPhoneNumber5() {
    PhoneNumber pn{"+1-2-coursera-cpp"};
    AssertEqual(pn.GetCountryCode(), "1");
    AssertEqual(pn.GetCityCode(), "2");
    AssertEqual(pn.GetLocalNumber(), "coursera-cpp");
    AssertEqual(pn.GetInternationalNumber(), "+1-2-coursera-cpp");
}

void TestAll() {
    TestRunner runner;
    runner.RunTest(TestPhoneNumber1, "TestPhoneNumber1");
    runner.RunTest(TestPhoneNumber2, "TestPhoneNumber2");
    runner.RunTest(TestPhoneNumber3, "TestPhoneNumber3");
    runner.RunTest(TestPhoneNumber4, "TestPhoneNumber4");
    runner.RunTest(TestPhoneNumber5, "TestPhoneNumber5");
}
