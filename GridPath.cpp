#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n;
    vector<vector<long long> > arr(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++) {
            if (str[j] == '*') arr[i][j] = -1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[0][i] == -1) {
            break;
        } else arr[0][i] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (arr[i][0] == -1) {
            break;
        } else arr[i][0] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            long long n1 = max(0LL, arr[i-1][j]);
            long long n2 = max(0LL, arr[i][j-1]);
            if (arr[i][j] != -1) arr[i][j] += (n1 + n2)%1000000007;
        }
    }
    cout << max(0LL, arr[n-1][n-1]) << endl;
    return 0;
}