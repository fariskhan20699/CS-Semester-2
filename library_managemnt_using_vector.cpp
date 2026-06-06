#include <iostream>
#include <vector>
using namespace std;

class Book{
protected:
    string title, author;
    int Id;
    bool isAvailable;

public:
    Book(string t, string a, int id) : title(t), author(a), Id(id){
        isAvailable = true;
    }

    void borrowBook(){
        if(isAvailable){
            isAvailable = false;
            cout << title << " Book Borrowed Successfully\n";
        }
        else{
            cout << title << " Book Already Borrowed\n";
        }
    }

    void returnBack(){
        if(!isAvailable){
            isAvailable = true;
            cout << title << " Book Returned Successfully\n";
        }
        else{
            cout << title << " Book Was Not Borrowed\n";
        }
    }

    virtual void display() = 0;
    virtual float fineCalculate(int dayLate) = 0;

    virtual ~Book(){}
};

// Fiction Book
class FictionBook : public Book{
public:
    FictionBook(string t, string a, int id)
        : Book(t, a, id){}

    void display() override{
        cout << "\n===== Fiction Book =====\n";
        cout << "Title      : " << title << endl;
        cout << "Author     : " << author << endl;
        cout << "ID         : " << Id << endl;
        cout << "Status     : "
             << (isAvailable ? "Available" : "Borrowed") << endl;
        cout << "========================\n";
    }

    float fineCalculate(int dayLate) override{
        return dayLate * 10;
    }
};

// Academic Book
class AcademicBook : public Book{
public:
    AcademicBook(string t, string a, int id)
        : Book(t, a, id){}

    void display() override{
        cout << "\n===== Academic Book =====\n";
        cout << "Title      : " << title << endl;
        cout << "Author     : " << author << endl;
        cout << "ID         : " << Id << endl;
        cout << "Status     : "
             << (isAvailable ? "Available" : "Borrowed") << endl;
        cout << "=========================\n";
    }

    float fineCalculate(int dayLate) override{
        return dayLate * 20;
    }
};

// Reference Book
class ReferenceBook : public Book{
public:
    ReferenceBook(string t, string a, int id)
        : Book(t, a, id){}

    void display() override{
        cout << "\n===== Reference Book =====\n";
        cout << "Title      : " << title << endl;
        cout << "Author     : " << author << endl;
        cout << "ID         : " << Id << endl;
        cout << "Status     : "
             << (isAvailable ? "Available" : "Borrowed") << endl;
        cout << "==========================\n";
    }

    float fineCalculate(int dayLate) override{
        return dayLate * 30;
    }
};

int main(){

    vector<Book*> books;

    books.push_back(
        new FictionBook("Harry Potter", "J.K Rowling", 1001));

    books.push_back(
        new AcademicBook("Data Structure", "Mark Allen", 1002));

    books.push_back(
        new ReferenceBook("Encyclopedia", "Oxford", 1003));

    cout << "\n------ ALL BOOKS ------\n";

    for(auto b : books){
        b->display();
    }

    cout << "\n------ BORROW TEST ------\n";

    books[0]->borrowBook();
    books[1]->borrowBook();

    cout << "\n------ STATUS AFTER BORROW ------\n";

    for(auto b : books){
        b->display();
    }

    cout << "\n------ RETURN TEST ------\n";

    books[0]->returnBack();

    cout << "\n------ STATUS AFTER RETURN ------\n";

    for(auto b : books){
        b->display();
    }

    cout << "\n------ FINE CALCULATION ------\n";

    int daysLate = 5;

    cout << "Fiction Book Fine (5 Days)   : Rs. "
         << books[0]->fineCalculate(daysLate) << endl;

    cout << "Academic Book Fine (5 Days)  : Rs. "
         << books[1]->fineCalculate(daysLate) << endl;

    cout << "Reference Book Fine (5 Days) : Rs. "
         << books[2]->fineCalculate(daysLate) << endl;

    for(auto b : books){
        delete b;
    }

    books.clear();

    return 0;
}
