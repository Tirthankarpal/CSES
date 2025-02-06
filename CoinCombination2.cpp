
#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<vector<int> > dp(n + 1, vector<int>(x + 1, 0));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            dp[i][j] = dp[i - 1][j]; 
            if (j >= arr[i - 1]) {
                dp[i][j] = (dp[i][j] + dp[i][j - arr[i - 1]]) % MOD; 
            }
        }
    }
    cout << dp[n][x] << endl;
    return 0;
}