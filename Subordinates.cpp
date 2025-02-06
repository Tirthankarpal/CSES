#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
int dynamic(int baap, vector<vector<int> >& adj, vector<int>& dp) {
    if (dp[baap] != -1) return dp[baap];
    int beta = 0;
    for (int i = 0; i < adj[baap].size(); i++) {
        beta += 1 + dynamic(adj[baap][i], adj, dp);
    }
    return dp[baap] = beta;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int> > adj(n);
    vector<int> dp(n, -1);
    for (int i = 0; i < n - 1; i++) {
        int num;
        cin >> num;
        adj[num - 1].push_back(i + 1);
    }
    for (int i = 0; i < n; i++) {
        if (dp[i] != -1) cout << dp[i] << " ";
        else cout << dynamic(i, adj, dp) << " ";
    }
    cout << endl;
    return 0;
}
