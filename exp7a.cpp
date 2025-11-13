//Program 2: Demonstration of Multiple Inheritance in C++ with Person, Faculty, Student, and TA
#include <iostream>
using namespace std;

class Person {
public:
    Person() { cout << "Person's constructor called\n"; }
};

class Faculty : public Person {
public:
    Faculty() { cout << "Faculty's constructor called\n"; }
};

class Student : public Person {
public:
    Student() { cout << "Student's constructor called\n"; }
};

class TA : public Faculty, public Student {
public:
    TA() { cout << "TA's constructor called\n"; }
};

int main() {
    TA ta;
    return 0;
}
