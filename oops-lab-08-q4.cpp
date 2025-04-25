#include <iostream>
#include <string>
using namespace std;

class Media {
protected:
    string title;
    int id;
    bool isBorrowed;

public:
    Media() {
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter ID: ";
        cin >> id;
        cin.ignore();
        isBorrowed = false;
    }

    Media(string t, int i) : title(t), id(i), isBorrowed(false) {}

    void borrowMedia() {
        if (!isBorrowed) {
            isBorrowed = true;
            cout << "Media borrowed successfully.\n";
        } else {
            cout << "Already borrowed.\n";
        }
    }

    void returnMedia() {
        if (isBorrowed) {
            isBorrowed = false;
            cout << "Media returned successfully.\n";
        } else {
            cout << "Media was not borrowed.\n";
        }
    }

    virtual void displayInfo() {
        cout << "Title: " << title << "\nID: " << id
             << "\nStatus: " << (isBorrowed ? "Borrowed" : "Available") << endl;
    }
};

class BookInfo {
protected:
    string author;

public:
    BookInfo() {
        cout << "Enter author: ";
        getline(cin, author);
    }

    BookInfo(string a) : author(a) {}

    void displayBookInfo() {
        cout << "Author: " << author << endl;
    }
};

class MagazineInfo {
protected:
    int issueNumber;

public:
    MagazineInfo() {
        cout << "Enter issue number: ";
        cin >> issueNumber;
        cin.ignore();
    }

    MagazineInfo(int issue) : issueNumber(issue) {}

    void displayMagazineInfo() {
        cout << "Issue Number: " << issueNumber << endl;
    }
};

class DVDInfo {
protected:
    string director;

public:
    DVDInfo() {
        cout << "Enter director: ";
        getline(cin, director);
    }

    DVDInfo(string d) : director(d) {}

    void displayDVDInfo() {
        cout << "Director: " << director << endl;
    }
};

class Book : public Media, public BookInfo {
public:
    Book(string t, int i, string a) : Media(t, i), BookInfo(a) {}

    void displayInfo() override {
        Media::displayInfo();
        displayBookInfo();
    }
};

class Magazine : public Media, public MagazineInfo {
public:
    Magazine(string t, int i, int issue) : Media(t, i), MagazineInfo(issue) {}

    void displayInfo() override {
        Media::displayInfo();
        displayMagazineInfo();
    }
};

class DVD : public Media, public DVDInfo {
public:
    DVD(string t, int i, string d) : Media(t, i), DVDInfo(d) {}

    void displayInfo() override {
        Media::displayInfo();
        displayDVDInfo();
    }
};

int main() {
 
    Book b("Treasure Island", 101, "Robert Louis Stevenson");
    b.borrowMedia();
    b.displayInfo();
    b.returnMedia();

    cout << "\n";

    Magazine m("Tech Monthly", 202, 55);
    m.displayInfo();

    cout << "\n";

    DVD d("The Ghost and the Darkness", 303, "Stephen Hopkins");
    d.borrowMedia();
    d.displayInfo();

    return 0;
}
