#include <iostream>
#include <vector>

using namespace std;

class Movie {
private:
    string movieName;
    string showTime;

public:
    Movie(string name, string time) {
        movieName = name;
        showTime = time;
    }

    void displayMovie() {
        cout << "Movie: " << movieName << " | Showtime: " << showTime << endl;
    }
};

class Ticket {
private:
    int rowNumber;
    int seatNumber;
    int ticketID;
    bool isSold;

public:
    Ticket(int rollNo, int row, int seat) {
        ticketID = rollNo / 100;  
        rowNumber = row;
        seatNumber = seat;
        isSold = false;
    }

    void sellTicket() {
        isSold = true;
    }

    void displayTicket() {
        cout << "Ticket ID: " << ticketID 
             << " | Row: " << rowNumber 
             << " | Seat: " << seatNumber 
             << " | Status: " << (isSold ? "Sold" : "Available") << endl;
    }
};

int main() {
    Movie movie1("Inception", "7:00 PM");
    Movie movie2("The Ghost and the Darkness", "9:00 PM");
    Movie movie3("Venom 2", "11:00 PM");
    movie1.displayMovie();
    movie2.displayMovie();
    movie3.displayMovie();

    Ticket ticket1(183, 5, 12); 
    Ticket ticket2(183, 6, 23); 
    Ticket ticket3(183, 7, 13);
    ticket1.displayTicket();
    ticket2.displayTicket();
    ticket3.displayTicket();


    cout << "\nSelling the ticket...\n";
    ticket1.sellTicket();
    ticket3.sellTicket();
    ticket1.displayTicket();
    ticket3.displayTicket();

    return 0;
}
