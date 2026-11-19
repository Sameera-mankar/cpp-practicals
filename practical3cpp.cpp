#include <iostream>
#include <utility>
using namespace std;

class DynamicArray
{
    int *data;
    int size;

public:
    DynamicArray()
    {
        data = 0;
        size = 0;
    }
    DynamicArray(int n)
    {
        if (n > 0)
        {
            size = n;
            data = new int[size]();
        }
        else
        {
            size = 0;
            data = 0;
        }
    }
    DynamicArray(const DynamicArray &obj)
    {
        size = obj.size;

        if (size > 0)
        {
            data = new int[size];

            for (int i = 0; i < size; i++)
            {
                data[i] = obj.data[i];
            }
        }
        else
        {
            data = 0;
        }
    }
    DynamicArray &operator=(const DynamicArray &obj)
    {
        if (this != &obj)
        {
            int *newData = 0;

            if (obj.size > 0)
            {
                newData = new int[obj.size];

                for (int i = 0; i < obj.size; i++)
                {
                    newData[i] = obj.data[i];
                }
            }

            delete[] data;

            size = obj.size;
            data = newData;
        }

        return *this;
    }

    DynamicArray(DynamicArray &&obj)
    {
        size = obj.size;
        data = obj.data;

        obj.size = 0;
        obj.data = 0;
    }
    DynamicArray &operator=(DynamicArray &&obj)
    {
        if (this != &obj)
        {
            delete[] data;

            size = obj.size;
            data = obj.data;

            obj.size = 0;
            obj.data = 0;
        }

        return *this;
    }

    ~DynamicArray()
    {
        delete[] data;
    }

    void inputElements()
    {
        cout << "Enter " << size << " array elements: ";

        for (int i = 0; i < size; i++)
        {
            cin >> data[i];
        }
    }

    void showElements()
    {
        cout << "Array elements: ";

        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }

        cout << "\n";
    }
};
int main()
{
    cout << "Student Name: SAMEERA MANKAR\n";
    cout << "URN: E25B000297\n\n";

    DynamicArray first;

    DynamicArray second(5);
    second.inputElements();
    second.showElements();

    DynamicArray third(second);
    third.showElements();

    first = second;
    first.showElements();

    DynamicArray fourth(std::move(second));
    fourth.showElements();

    DynamicArray fifth;
    fifth = std::move(third);
    fifth.showElements();

    return 0;
}



