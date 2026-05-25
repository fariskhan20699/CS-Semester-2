#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    int id;
    string title;
    string author;
    bool issued;

public:
    // Constructor
    Book() {
        id = 0;
        title = "";
        author = "";
        issued = false;
    }

    // Set Book Data
    void addBook(int bId, string bTitle, string bAuthor) {
        id = bId;
        title = bTitle;
        author = bAuthor;
        issued = false;
    }

    // Display Book
    void displayBook() {
        cout << "\nBook ID: " << id;
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;

        if (issued)
            cout << "\nStatus: Issued";
        else
            cout << "\nStatus: Available";

        cout << "\n----------------------\n";
    }

    // Issue Book
    void issueBook() {
        if (!issued) {
            issued = true;
            cout << "Book Issued Successfully\n";
        }
        else {
            cout << "Book Already Issued\n";
        }
    }

    // Return Book
    void returnBook() {
        if (issued) {
            issued = false;
            cout << "Book Returned Successfully\n";
        }
        else {
            cout << "Book Was Not Issued\n";
        }
    }

    int getId() {
        return id;
    }
};

int main() {

    Book books[3];

    books[0].addBook(101, "OOP in C++", "Ali");
    books[1].addBook(102, "Data Structures", "Ahmed");
    books[2].addBook(103, "Programming Fundamentals", "Sara");

    int choice, searchId;

    do {
        cout << "\n===== LIBRARY MENU =====\n";
        cout << "1. Display All Books\n";
        cout << "2. Issue Book\n";
        cout << "3. Return Book\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            for (int i = 0; i < 3; i++) {
                books[i].displayBook();
            }
            break;

        case 2:
            cout << "Enter Book ID: ";
            cin >> searchId;

            for (int i = 0; i < 3; i++) {
                if (books[i].getId() == searchId) {
                    books[i].issueBook();
                }
            }
            break;

        case 3:
            cout << "Enter Book ID: ";
            cin >> searchId;

            for (int i = 0; i < 3; i++) {
                if (books[i].getId() == searchId) {
                    books[i].returnBook();
                }
            }
            break;

        case 4:
            cout << "Program Ended\n";
            break;

        default:
            cout << "Invalid Choice\n";
        }

    } while (choice != 4);

    return 0;
}