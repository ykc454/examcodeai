#include <iostream>
using namespace std;

void hanoi(int n, char source, char auxiliary, char destination) {
    if (n == 0){
        return;
    }

    hanoi(n - 1, source, destination, auxiliary);

    cout << "Move disk " << n << " from "
         << source << " to " << destination << endl;

    hanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;

    cout << "Enter number of disks: ";
    cin >> n;

    hanoi(n, 'A', 'B', 'C');

    return 0;
}