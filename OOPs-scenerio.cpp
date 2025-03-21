#include <iostream>

using namespace std;

class Transaction
{
private:
  string prod_id;
  string salesper_id;
  static int revenue; // so here we declared the static member 'revenue'
public:
  const double prod_price = 1000;
  const double revenue_per_transaction = 150;

  Transaction() {}
  Transaction(string p_id, string s_id)
  {

    prod_id = p_id;
    salesper_id = s_id;
    revenue += revenue_per_transaction;
  }

  void displaytransactions(int trans)
  {

    cout << "\nTransactons: " << trans << endl;
    cout << "Sales man ID: " << salesper_id << endl;
    cout << "Product ID: " << prod_id << endl;
    cout << "Product price: " << prod_price << "Rs" << endl;
    cout << "Revenue per transaction: " << revenue_per_transaction << "Rs" << endl
         << endl;
  }
  static int getRevenue()
  {
    return revenue;
  }
};
int Transaction::revenue = 0;
// revenue+= revenue_per_transaction
// return revenue;

int main()
{
  // Transaction e1;
  // cout<<e1.prod_price;
  int n;
  cout << "Enter the number of transactions: " << endl
       << endl;
  cin >> n;
  Transaction *transactions = new Transaction[n];

  for (int i = 0; i < n; i++)
  {
    string p_id, s_id;
    cout << "Enter product ID for transaction " << i + 1 << endl;
    cin >> p_id;
    cout << "Enter sales person ID for transaction " << i + 1 << endl;
    cin >> s_id;

    new (&transactions[i]) Transaction(p_id, s_id); 
    // acha tw yahan call by address kia hy transaction ko becaz
     // we point towards transactions in line 51 :)
  }
  for (int i = 0; i < n; i++)
  {

    transactions[i].displaytransactions(i + 1);
  }

  cout << "\n Total Revenue Of the Transactions is: " << Transaction::getRevenue() << "Rs" << endl;

  delete[] transactions;

  return 0;
}