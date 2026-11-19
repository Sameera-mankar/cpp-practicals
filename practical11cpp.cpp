#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student
{
    int Id;
    string name;
    float marks;
};

int main()
{
    cout << "Student name: SAMEERA MANKAR\nURN: E25B000297\n\n";

    Student records[] = {
        {101, "Rahul", 85.5},
        {102, "Priya", 78.0},
        {103, "Amit", 92.5}
    };

    // Writing student records to CSV file
    fstream file("students.csv", ios::out);

    if (!file)
    {
        cout << "Unable to open file!";
        return 1;
    }

    file << "ID,Name,Marks\n";

    for (int i = 0; i < 3; i++)
    {
        file << records[i].Id << "," << records[i].name
             << "," << records[i].marks << "\n";
    }

    if (!file)
    {
        cout << "Error writing to file!";
        return 1;
    }

    file.close();
    cout << "Student records saved successfully!\n";

    // Reading student records from CSV file
    fstream in("students.csv", ios::in);

    if (!in)
    {
        cout << "Unable to open file!";
        return 1;
    }

    string line;
    getline(in, line);  // Skip heading

    cout << "\nStudent Records:\n";
    cout << "ID\tName\tMarks\n";

    while (getline(in, line))
    {
        if (line.empty())
            continue;

        if (line.find(',') == string::npos ||
            line.find(',', line.find(',') + 1) == string::npos)
        {
            cout << "Skipping malformed record.\n";
            continue;
        }

        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] == ',')
            {
                line[i] = '\t';
            }
        }

        cout << line << "\n";
    }

    in.close();

    // Demonstration of tellg() and seekg()
    fstream readFile("students.csv", ios::in);

    cout << "\nRead Position Demonstration:\n";
    cout << "Initial position: " << readFile.tellg() << "\n";

    readFile.seekg(5);
    cout << "Position after seekg(5): " << readFile.tellg() << "\n";

    char ch;
    readFile.get(ch);
    cout << "Character at position 5: " << ch << "\n";

    readFile.close();

    // Demonstration of tellp() and seekp()
    fstream writeFile("demo.txt", ios::out);

    if (!writeFile)
    {
        cout << "Unable to open demo file!";
        return 1;
    }

    writeFile << "ABCDE";

    cout << "\nWrite Position Demonstration:\n";
    cout << "Position after writing ABCDE: " << writeFile.tellp() << "\n";

    writeFile.seekp(1);
    cout << "Position after seekp(1): " << writeFile.tellp() << "\n";

    writeFile << "X";
    writeFile.close();

    cout << "Updated content of demo.txt: AXCDE\n";

    return 0;
}

