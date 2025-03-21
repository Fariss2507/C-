#include <iostream>
#include <string>
using namespace std;
// Address class
class Address {
public:
    string street, city, state, country;
    int postalCode;
};


class Author {
public:
    string name, description;

    string getName() {
        return name;
    }
};

class Library {
public:
    string name;
    Address address;

    Address getAddress() {
        return address;
    }
};


class Book {
public:
    string ISBN, title, subject, publisher, language;
    int numberOfPages;

    string getTitle() {
        return title;
    }
};


class Rack {
public:
    int number;
    string locationIdentifier;
};


class BookItem : public Book {
public:
    string barcode;
    bool isReferenceOnly;
    string borrowed, dueDate;
    double price;
    string format, status;
    string dateOfPurchase, publicationDate;

    bool checkout() {
        return !isReferenceOnly;
    }
};
