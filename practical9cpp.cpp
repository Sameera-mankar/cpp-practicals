#include <iostream>
#include <stack>
#include <string>
using namespace std;

template <class T>
class StackBox
{
    stack<T> st;

public:
    void push(T val)
    {
        st.push(val);
    }

    void pop()
    {
        if (!st.empty())
        {
            cout << "Popped element: " << st.top() << "\n";
            st.pop();
        }
        else
        {
            cout << "Stack underflow.\n";
        }
    }

    void top()
    {
        if (!st.empty())
        {
            cout << "Top element: " << st.top() << "\n";
        }
        else
        {
            cout << "Stack underflow.\n";
        }
    }

    void display()
    {
        if (st.empty())
        {
            cout << "Stack empty.\n";
            return;
        }
        else
        {
            cout << "Elements of stack are (top -> bottom): ";
            stack<T> temp = st;

            while (!temp.empty())
            {
                cout << temp.top() << " ";
                temp.pop();
            }

            cout << "\n";
        }
    }
};

int main()
{
    cout << "Student name: SAMEERA MANKAR\n";
    cout << "URN: E25B000297\n\n";

    cout << "Integer stack:\n";
    StackBox<int> a;
    a.push(15);
    a.push(25);
    a.push(35);
    a.display();
    a.top();
    a.pop();
    a.display();

    cout << "\nFloat stack:\n";
    StackBox<float> b;
    b.push(1.2f);
    b.push(2.4f);
    b.push(3.6f);
    b.display();
    b.pop();

    cout << "\nString stack:\n";
    StackBox<string> c;
    c.push("Good");
    c.push("Morning");
    c.display();
    c.pop();

    return 0;
}

