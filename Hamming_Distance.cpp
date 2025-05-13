#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        arr[i]=stoi(str, nullptr, 2);
    }
    int res=32;
    for (int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            res=min(res,__builtin_popcount(arr[i]^arr[j]));
        }
    }
    cout << res << endl;
    return 0;
}