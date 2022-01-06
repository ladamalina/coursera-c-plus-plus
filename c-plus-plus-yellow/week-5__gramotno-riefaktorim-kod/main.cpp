#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
    Person(const string& name, const string& role) : name_(name), role_(role) {}

    virtual void Walk(const string& destination) const {
        cout << role_ << ": " << name_ << " walks to: " << destination << endl;
    }

    string Name() const {
        return name_;
    }

    string Role() const {
        return role_;
    }

    void VisitPlaces(const vector<string>& places) {
        for (const string& p : places) {
            Walk(p);
        }
    }

protected:
    const string name_;
    const string role_;
};

class Student : public Person {
public:
    Student(const string& name, const string& favourite_song) : Person(name, "Student"), favourite_song_(favourite_song) {}

    void Learn() const {
        cout << role_ << ": " << name_ << " learns" << endl;
    }

    void SingSong() const {
        cout << role_ << ": " << name_ << " sings a song: " << favourite_song_ << endl;
    }

    void Walk(const string& destination) const override {
        cout << role_ << ": " << name_ << " walks to: " << destination << endl;
        SingSong();
    }

private:
    const string favourite_song_;
};


class Teacher : public Person {
public:
    Teacher(const string& name, const string& subject) : Person(name, "Teacher"), subject_(subject) {}

    void Teach() const {
        cout << role_ << ": " << name_ << " teaches: " << subject_ << endl;
    }

private:
    const string subject_;
};


class Policeman : public Person {
public:
    Policeman(const string& name) : Person(name, "Policeman") {}

    void Check(const Person& p) const {
        cout << role_ << ": " << name_ << " checks " << p.Role() << ". " << p.Role() << "'s name is: " << p.Name() << endl;
    }
};


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    t.VisitPlaces({"Moscow", "London"});
    p.Check(s);
    s.VisitPlaces({"Moscow", "London"});

    return 0;
}
