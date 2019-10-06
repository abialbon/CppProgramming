#include <iostream>
#include "Sales_item.h"

using namespace std;

int main() {
    Sales_item cur_item;
    Sales_item acc_item;
    while(cin >> cur_item) {
        cout << cur_item.isbn() << endl;
        acc_item += cur_item;
    }
    cout << "The total of all transactions: " << endl;
    cout << acc_item << endl;
    cout << acc_item.isbn() << endl;
    return 0;    
}