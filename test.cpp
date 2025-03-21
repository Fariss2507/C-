/*
    BCIT
    Muhammad Shaheer CT-182
*/

#include <iostream>
using namespace std;

class Transaction
{
private:
    string ProdId;
    string SalesPersonId;
    static const int ProdPrice = 1000; // ye idhr constant krdia hy 
    int RevenuePerTransaction;  // isko bhi idhr hi constant krdena 
    static int TotalRevenue;
    static int transaction_no;

public:
    Transaction() {}  //: ProdId(""), SalesPersonId(""), RevenuePerTransaction(0) {}

    Transaction(string pid, string spid, int rpt) : ProdId(pid), SalesPersonId(spid), RevenuePerTransaction(rpt) {}

    void PrintInfo() const
    {
        cout << "Transaction No: " << transaction_no << endl;
        cout << "SalesPerson ID: " << SalesPersonId << endl;
        cout << "Product ID: " << ProdId << endl;
        cout << "Product Price: " << ProdPrice << endl;
        cout << "Revenue Per Transaction: " << RevenuePerTransaction << " rs" << endl;
        cout << "\n\n";
    }

    void AddtoTotal()
    {
        TotalRevenue += RevenuePerTransaction;
    }

    static int GetTotalRev()
    {
        return TotalRevenue;
    }

    static void IncTransaction()
    {
        transaction_no++;
    }
};

int Transaction::TotalRevenue = 0;
int Transaction::transaction_no = 0;

int main()
{
    Transaction arr[10] = {
        {"Dairy01", "Babar01", 200},  // baki tum isko bhi constant krdena ye jo 
        {"Dairy01", "Asim01", 300},   //revenue per transaction hy 
        {"Dairy01", "Ali01", 120},
        {"Dairy01", "Huzaifa01", 100},
        {"CarPart01", "Asim01", 500},
        {"Canned01", "Ali01", 230},
        {"Electronic01", "Babar01", 135},
        {"Kitchenware01", "Babar01", 150},
        {"Laundry01", "Asim01", 150},
        {"Cosmetic01", "Huzaifa01", 350}
    };

    for (int i = 0; i < 10; i++)
    {
        Transaction::IncTransaction();
        arr[i].AddtoTotal();
        arr[i].PrintInfo();
    }

    cout << "Total Revenue generated: " << Transaction::GetTotalRev() << " rs" << endl;

    return 0;
}
