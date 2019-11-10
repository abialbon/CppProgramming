#include <iostream>
using namespace std;

int main() {
    int balance = 420;
    int wash_cost = 360;
    int no_wahses = 0;
    int recharge = 500;
    int no_recharges = 0;

    while (balance != 0 && no_wahses < 100) {
        if (balance >= wash_cost) {
            ++no_wahses;
            balance -= wash_cost;
        } else {
            balance += recharge;
            ++no_recharges;
        }
    }
    cout << "No of washes yet : " << no_wahses << endl;
    cout << "No of recharges yet : " << no_recharges << endl;
    cout << "Balance : " << balance << endl;
}
