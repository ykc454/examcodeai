
#include <iostream>
using namespace std;

int main() {
    char A, B;
    char location = 'A';

    cout << "Enter status of Room A (C = Clean, D = Dirty): ";
    cin >> A;

    cout << "Enter status of Room B (C = Clean, D = Dirty): ";
    cin >> B;

    cout << "\nVacuum Cleaner Agent Started\n";

    while (A == 'D' || B == 'D') {
        if (location == 'A') {
            if (A == 'D') {
                cout << "Room A is Dirty -> Suck\n";
                A = 'C';
            } else {
                cout << "Room A is Clean -> Move Right to B\n";
                location = 'B';
            }
        } else {
            if (B == 'D') {
                cout << "Room B is Dirty -> Suck\n";
                B = 'C';
            } else {
                cout << "Room B is Clean -> Move Left to A\n";
                location = 'A';
            }
        }
    }

    cout << "\nBoth rooms are clean!\n";
    cout << "Agent stopped.\n";

    return 0;
}
