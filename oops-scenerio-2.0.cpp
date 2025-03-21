#include <iostream>
using namespace std;

class Transaction {
private:
    string prod_id;     // Product ID as string
    string salesper_id; // SalesPerson ID as string
    static int revenue; // Static variable to store total revenue

public:
    const double prod_price = 1000;       // Constant product price
    const double revenue_per_transaction = 150; // Constant revenue per transaction

    // Constructor
    Transaction() {}  
    Transaction(string p_id, string s_id) {
        prod_id = p_id;
        salesper_id = s_id;
        revenue += revenue_per_transaction; // Update total revenue
    }

    // Display transaction details
    void displayTransactions(int trans) {
        cout << "Transaction: " << trans << endl;
        cout << "SalesPerson ID: " << salesper_id << endl;
        cout << "Product ID: " << prod_id << endl;
        cout << "Product Price: " << prod_price << " Rs" << endl;
        cout << "Revenue per Transaction: " << revenue_per_transaction << " Rs" << endl;
        cout << "------------------------------" << endl;
    }

    // Static function to get total revenue
    static int getRevenue() {
        return revenue;
    }
};

// Initialize static variable
int Transaction::revenue = 0;

int main() {
    int n;
    cout << "Enter the number of transactions: ";
    cin >> n;

    // Create a dynamic array for transactions
    Transaction* transactions = new Transaction[n];

    // Input transactions
    for (int i = 0; i < n; i++) {
        string p_id, s_id;
        cout << "Enter Product ID for Transaction " << i + 1 << ": ";
        cin >> p_id;
        cout << "Enter SalesPerson ID for Transaction " << i + 1 << ": ";
        cin >> s_id;

        transactions[i] = Transaction(p_id, s_id);  // Store transaction
    }

    // Display transactions
    for (int i = 0; i < n; i++) {
        transactions[i].displayTransactions(i + 1);
    }

    // Display total revenue
    cout << "Total Revenue of the Transactions is: " << Transaction::getRevenue() << " Rs" << endl;

    // Free the allocated memory
    delete[] transactions;

    return 0;
}
