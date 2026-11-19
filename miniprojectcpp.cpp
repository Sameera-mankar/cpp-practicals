#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
using namespace std;

class LibraryItem
{
public:
    virtual void display() const = 0;
    virtual ~LibraryItem() {}
};
class Book : public LibraryItem
{
private:
    int id;
    string title;
    string author;
    bool available;

public:
    Book(int bookId, string bookTitle, string bookAuthor,
         bool status = true)
    {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
        available = status;
    }
    int getId() const
    {
        return id;
    }
    void issue()
    {
        if (!available)
            throw runtime_error("Book is already issued.");

        available = false;
    }
    void returnBook()
    {
        if (available)
            throw runtime_error("Book is already available.");

        available = true;
    }
    void display() const override
    {
        cout << id << " | " << title << " | "
             << author << " | "
             << (available ? "Available" : "Issued") << "\n";
    }
    void save(ofstream &file) const
    {
        file << id << "," << title << ","
             << author << "," << available << "\n";
    }
};
class Library
{
private:
    vector<Book> books;

public:
    Book* searchBook(int id)
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].getId() == id)
                return &books[i];
        }

        return nullptr;
    }
    void addBook(int id, string title, string author)
    {
        if (id <= 0 || title.empty() || author.empty())
            throw runtime_error("Invalid book details.");

        if (searchBook(id) != nullptr)
            throw runtime_error("Book ID already exists.");

        books.push_back(Book(id, title, author));
    }
    void displayBooks() const
    {
        cout << "ID | Title | Author | Status\n";

        for (int i = 0; i < books.size(); i++)
        {
            const LibraryItem *item = &books[i];
            item->display();
        }
    }
    void issueBook(int id)
    {
        Book *book = searchBook(id);

        if (book == nullptr)
            throw runtime_error("Book ID not found.");

        book->issue();
    }
    void returnBook(int id)
    {
        Book *book = searchBook(id);

        if (book == nullptr)
            throw runtime_error("Book ID not found.");

        book->returnBook();
    }
    void saveToFile() const
    {
        ofstream file("library.csv");

        if (!file)
            throw runtime_error("Unable to open file.");

        for (int i = 0; i < books.size(); i++)
        {
            books[i].save(file);
        }

        if (!file)
            throw runtime_error("Error saving records.");
    }
    void loadFromFile()
    {
        ifstream file("library.csv");
        if (!file)
            return;

        string line;

        while (getline(file, line))
        {
            stringstream row(line);
            string id, title, author, status;

            if (!getline(row, id, ',') ||
                !getline(row, title, ',') ||
                !getline(row, author, ',') ||
                !getline(row, status))
                continue;
            try
            {
                int bookId = stoi(id);
                int available = stoi(status);
                if (bookId <= 0 || title.empty() ||
                    author.empty() ||
                    (available != 0 && available != 1) ||
                    searchBook(bookId) != nullptr)
                    continue;

                books.push_back(
                    Book(bookId, title, author, available == 1)
                );
            }
            catch (const exception &)
            {
                continue;
            }
        }
    }
};
int main()
{
    cout << "Student Name: SAMEERA MANKAR\n";
    cout << "URN: E25B000297\n\n";
    try
    {
        Library library;
        library.loadFromFile();
        if (library.searchBook(101) == nullptr &&
            library.searchBook(102) == nullptr &&
            library.searchBook(103) == nullptr)
        {
            library.addBook(101, "C++ Programming",
                            "E. Balagurusamy");

            library.addBook(102, "Data Structures",
                            "Mark Allen");

            library.addBook(103, "Computer Networks",
                            "Andrew Tanenbaum");
        }
        cout << "BOOK RECORDS:\n";
        library.displayBooks();

        cout << "\nISSUE BOOK 101:\n";
        library.issueBook(101);
        cout << "Book issued successfully.\n";

        cout << "\nTRY TO ISSUE BOOK 101 AGAIN:\n";
        try
        {
            library.issueBook(101);
        }
        catch (const exception &e)
        {
            cout << "Error: " << e.what() << "\n";
        }
        cout << "\nRETURN BOOK 101:\n";
        library.returnBook(101);
        cout << "Book returned successfully.\n";

        library.saveToFile();

        cout << "\nBook records saved to library.csv.\n";
        cout << "\nFINAL BOOK RECORDS:\n";
        library.displayBooks();
    }
    catch (const exception &e)
    {
        cout << "Application error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}

