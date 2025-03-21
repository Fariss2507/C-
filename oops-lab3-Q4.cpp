#include <iostream>
#include <string>
using namespace std;

class bookType {
private:
    string title, author, publisher, ISBN;
    double price;
    int copies;

public:
    
    bookType(string t = "", string a = "", string p = "", string i = "", double pr = 0.0, int c = 0) {
        title = t;
        author = a;
        publisher = p;
        ISBN = i;
        price = pr;
        copies = c;
    }

   
    void showBook() {
        cout << "\nTitle: " << title << "\nAuthor: " << author
             << "\nPublisher: " << publisher << "\nISBN: " << ISBN
             << "\nPrice: $" << price << "\nCopies in Stock: " << copies << endl;
    }

  
    void updateStock(int c) { copies += c; }

  
    bool searchByTitle(string t) // im uising bool functions here for the search
     { return title == t; }
    bool searchByISBN(string i) 
    { return ISBN == i; }
};

int main() {
    bookType books[3] = {
        bookType("Harry Potter", "J.K. Rowling", "Bloomsbury", "12345", 29.99, 10),
        bookType("1984", "George Orwell", "Penguin", "67890", 19.99, 5),
        bookType("The Great Gatsby", "F. Scott Fitzgerald", "Scribner", "54321", 15.99, 7)
    };

    
    string searchTitle = "Harry Potter";
    for (int i = 0; i < 3; i++) {
        if (books[i].searchByTitle(searchTitle)) {
            cout << "\nBook found by Title:\n";
            books[i].showBook();
        }
    }

    string searchISBN = "67890";
    for (int i = 0; i < 3; i++) {
        if (books[i].searchByISBN(searchISBN)) {
            cout << "\nBook found by ISBN:\n";
            books[i].showBook();
        }
    }

    
    books[0].updateStock(5);
    cout << "\nUpdated stock for Harry Potter:\n";
    books[0].showBook();

    return 0;
}
