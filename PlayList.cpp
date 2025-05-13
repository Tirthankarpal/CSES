#include "bits/stdc++.h"
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    map<long long, long long> map;
    long long len = 0;
    long long st = 0;

    for (int j = 0; j < n; j++) {
        if (map.find(arr[j]) != map.end() && map[arr[j]] >= st) {
            st = map[arr[j]] + 1;
        }
        map[arr[j]] = j;
        len = max(len, j - st + 1);
    }

    cout << len << endl;
    return 0;
}
