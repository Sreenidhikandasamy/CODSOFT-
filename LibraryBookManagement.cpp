#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Book {
public:
    string title;
    string author;
    string ISBN;
    bool available;
    bool overdue;

    Book(const string& t, const string& a, const string& isbn)
        : title(t), author(a), ISBN(isbn), available(true), overdue(false) {}
};

class Borrower {
public:
    string name;
    int borrowedBooks;

    Borrower(const string& n) : name(n), borrowedBooks(0) {}
};

class Library {
private:
    vector<Book> books;
    vector<Borrower> borrowers;
    const double fineRate = 0.5;

public:
    void addBook(const string& title, const string& author, const string& ISBN) {
        books.push_back(Book(title, author, ISBN));
        cout << "Book added to the library: " << title << endl;
    }

    void displayBooks() const {
        cout << "Library Catalog:\n";
        for (const auto& book : books) {
            cout << "Title: " << book.title << "\tAuthor: " << book.author
                << "\tISBN: " << book.ISBN << "\tStatus: " << (book.available ? "Available" : "Checked Out")
                << "\tOverdue: " << (book.overdue ? "Yes" : "No") << endl;
        }
    }

    void searchBooks(const string& keyword) const {
        cout << "Search Results:\n";
        for (const auto& book : books) {
            if (book.title.find(keyword) != string::npos ||
                book.author.find(keyword) != string::npos ||
                book.ISBN.find(keyword) != string::npos) {
                cout << "Title: " << book.title << "\tAuthor: " << book.author
                    << "\tISBN: " << book.ISBN << "\tStatus: " << (book.available ? "Available" : "Checked Out")
                    << "\tOverdue: " << (book.overdue ? "Yes" : "No") << endl;
            }
        }
    }

    void checkoutBook(const string& ISBN, const string& borrowerName) {
        auto it = find_if(books.begin(), books.end(), [&](const Book& b) { return b.ISBN == ISBN && b.available; });

        if (it != books.end()) {
            it->available = false;
            it->overdue = false;
            auto borrowerIt = find_if(borrowers.begin(), borrowers.end(), [&](const Borrower& br) { return br.name == borrowerName; });

            if (borrowerIt != borrowers.end()) {
                borrowerIt->borrowedBooks++;
                cout << "Book checked out successfully to " << borrowerName << endl;
            } else {
                borrowers.push_back(Borrower(borrowerName));
                borrowers.back().borrowedBooks++;
                cout << "Book checked out successfully to a new borrower: " << borrowerName << endl;
            }
        } else {
            cout << "Book with ISBN " << ISBN << " not found or not available for checkout." << endl;
        }
    }

    void returnBook(const string& ISBN) {
        auto it = find_if(books.begin(), books.end(), [&](const Book& b) { return b.ISBN == ISBN && !b.available; });

        if (it != books.end()) {
            it->available = true;
            auto borrowerIt = find_if(borrowers.begin(), borrowers.end(), [&](const Borrower& br) { return br.borrowedBooks > 0; });

            if (borrowerIt != borrowers.end()) {
                borrowerIt->borrowedBooks--;
                cout << "Book returned successfully." << endl;
            }


            if (it->overdue) {
                int daysOverdue;
                cout << "Enter the number of days the book was overdue: ";
                cin >> daysOverdue;
                double fine = fineRate * daysOverdue;
                cout << "Fine for overdue book: $" << fine << endl;
            }
        } else {
            cout << "Book with ISBN " << ISBN << " not found or already returned." << endl;
        }
    }
};

int main() {
    Library library;

    int choice;
    string title, author, ISBN, keyword, borrowerName;

    do {
        cout << "\n----------LIBRARY MANAGEMENT SYSTEM----------\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Books\n";
        cout << "4. Checkout Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter book title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter ISBN: ";
            getline(cin, ISBN);
            library.addBook(title, author, ISBN);
            break;
        case 2:
            library.displayBooks();
            break;
        case 3:
            cout << "Enter search keyword: ";
            cin.ignore();
            getline(cin, keyword);
            library.searchBooks(keyword);
            break;
        case 4:
            cout << "Enter book ISBN to checkout: ";
            cin.ignore();
            getline(cin, ISBN);
            cout << "Enter borrower name: ";
            getline(cin, borrowerName);
            library.checkoutBook(ISBN, borrowerName);
            break;
        case 5:
            cout << "Enter book ISBN to return: ";
            cin.ignore();
            getline(cin, ISBN);
            library.returnBook(ISBN);
            break;
        case 6:
            cout << "Exiting the program." << endl;
            cout<<"Thank you!"<<endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
