#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll sum = n * (n + 1LL) / 2;
    if (sum % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }
    sum /= 2;
    vector<vector<ll>> dp(n + 1, vector<ll>(sum + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            dp[i][j] = dp[i-1][j];
            if (j - i >= 0) {
                dp[i][j] = (dp[i][j] + dp[i-1][j - i]) % mod;
            }
        }
    }
    ll modInverse2 = (mod + 1) / 2;
    ll res = (dp[n][sum] * modInverse2) % mod;
    cout << res << endl;
    return 0;
}
