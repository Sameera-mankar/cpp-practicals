#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    Person()
    {
        name = "";
        age = 0;
    }

    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    void display()
    {
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
    }
};

// Employee inherits from Person.
class Employee : public Person
{
protected:
    string employeeId, department;

public:
    Employee()
    {
        name = "";
        age = 0;
        employeeId = "";
        department = "";
    }

    Employee(string name, int age, string employeeId, string department)
    {
        this->name = name;
        this->age = age;
        this->employeeId = employeeId;
        this->department = department;
    }

    void display()
    {
        Person::display();
        cout << "Employee ID: " << employeeId << "\n";
        cout << "Department: " << department << "\n";
    }
};

// TeamLeader inherits from Employee.
class TeamLeader : public Employee
{
private:
    string project;

public:
    TeamLeader(string name, int age, string employeeId,
               string department, string project)
    {
        this->name = name;
        this->age = age;
        this->employeeId = employeeId;
        this->department = department;
        this->project = project;
    }

    void display()
    {
        Employee::display();
        cout << "Project: " << project << "\n";
    }
};

int main()
{
    cout << "Student name: SAMEERA MANKAR\n";
    cout << "URN: E25B000297\n\n";

    Person a("Rahul", 25);
    a.display();
    cout << "\n";

    // Single Inheritance
    Employee b("Priya", 28, "E101", "IT");
    b.display();
    cout << "\n";

    // Multilevel Inheritance
    TeamLeader c("Amit", 30, "E102", "CSE", "Website Development");
    c.display();
    cout << "\n";

    return 0;
}

