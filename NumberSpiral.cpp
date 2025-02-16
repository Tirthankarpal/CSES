#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int s = 0; s < t; s++) {
        long long row, col;
        cin >> row >> col;
        if (row == col) {
            cout << row * row - row + 1 << endl;
        } else if (row > col) {
            long long start = 0;
            if (row % 2 == 0) {
                start = row * row;
                cout << start - col + 1 << endl;
            } else {
                start = (row - 1) * (row - 1) + 1;
                cout << start + col - 1 << endl;
            }
        } else {
            long long start = 0;
            if (col % 2 == 1) {
                start = col * col;
                cout << start - row + 1 << endl;
            } else {
                start = (col - 1) * (col - 1) + 1;
                cout << start + row - 1 << endl;
            }
        }
    }

    return 0;
}