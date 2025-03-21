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
   const int ProdPrice=1000;
    int RevenuePerTransaction;
    static int TotalRevenue;
    static int transaction_no;

public:
    Transaction()
    {
        ProdId = "";
        SalesPersonId = "";
        RevenuePerTransaction = 0;
      //  ProdPrice=0;
        RevenuePerTransaction = 0;
    }

    Transaction(string pid, string spid, int pp, int rpt)
    {
        ProdId = pid;
        SalesPersonId = spid;
      //  ProdPrice = pp;
        RevenuePerTransaction = rpt;
    }

    void PrintInfo() const
    {
        cout << "transaction_no" << transaction_no << endl;
        cout << "SalesPerson_id: " << SalesPersonId << endl;
        cout << "Product_id: " << ProdId << endl;
        cout << "Cost: " << ProdPrice << endl;
        cout << "Revenue Per transaction =  " << RevenuePerTransaction << "rs" << endl;
        cout << "\n\n";
    }

    void AddtoTotal()
    {
        TotalRevenue += RevenuePerTransaction;
    }

    static auto GetTotalRev()
    {
        return TotalRevenue;
    }

    static auto IncTransaction()
    {
        transaction_no++;
    }
};

int Transaction::TotalRevenue = 0;
int Transaction::transaction_no = 0;

int main()
{
    Transaction arr[10];
    arr[0] = Transaction("Dairy01", "Babar01", 1500, 200);
    arr[1] = Transaction("Dairy01", "Asim01", 2000, 300);
    arr[2] = Transaction("Dairy01", "Ali01", 3000, 120);
    arr[3] = Transaction("Dairy01", "Huzaifa01", 4500, 100);
    arr[4] = Transaction("CarPart01", "Asim01", 600, 500);
    arr[5] = Transaction("Canned01", "Ali01", 800, 230);
    arr[6] = Transaction("Electronic01", "Babar01", 350, 135);
    arr[7] = Transaction("Kitchenware01", "Babar01", 15000, 150);
    arr[8] = Transaction("Laundry01", "Asim01", 4000, 150);
    arr[9] = Transaction("Cosmetic01", "Huzaifa01", 1200, 350);

    for (int i = 0; i < 10; i++)
    {
        arr[i].IncTransaction();
        arr[i].AddtoTotal();
        arr[i].PrintInfo();
    }

    cout << "Total Revenue generated:  " << Transaction::GetTotalRev() << endl;

    return 0;
}

