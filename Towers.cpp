#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    multiset<int> towers;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        auto it = towers.upper_bound(num);
        if (it != towers.end()) {
            towers.erase(it);
            towers.insert(num);
        } else {
            towers.insert(num);
        }
    }
    
    cout<<towers.size()<<endl;
    return 0;
}