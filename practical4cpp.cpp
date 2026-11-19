#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Learner
{
public:
    string name;

    Learner(string n)
    {
        name = n;
    }

    void display()
    {
        cout << "Learner name: " << name << "\n";
    }

    ~Learner()
    {
        cout << "Memory released for: " << name << "\n";
    }
};

int main()
{
    cout << "Student name: SAMEERA MANKAR\n";
    cout << "URN: E25B000297\n\n";

    {
        unique_ptr<Learner> a =
            make_unique<Learner>("Rahul");

        a->display();
    }

    cout << "Unique ownership ends when its pointer leaves the scope.\n\n";

    {
        shared_ptr<Learner> b;

        {
            shared_ptr<Learner> c =
                make_shared<Learner>("Priya");

            b = c;
            c->display();
        }

        cout << "One shared owner remains, so the object is still available.\n";
    }

    cout << "All owners are gone. The shared object is now released.\n";

    return 0;
}

