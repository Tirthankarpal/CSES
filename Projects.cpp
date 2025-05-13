#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dynamic(ll i,ll last,vector<tuple<ll,ll,ll>>& arr,vector<vector<ll>>& dp) {
    if (i == arr.size()) {
        return dp[i][last]=0;
    }
    if (dp[i][last] != -1) {
        return dp[i][last];
    }
    ll skip= dynamic(i + 1,last, arr, dp);
    if (get<0>(arr[i]) <= last) {
        return dp[i][last]=skip;
    }
    ll take = get<2>(arr[i]) + dynamic(i + 1,get<1>(arr[i]), arr, dp);
    return dp[i][last]=max(skip,take);
}
int main() {
    ll n;
    cin >> n;
    vector<tuple<ll,ll,ll>> arr(n);
    ll max1 = 0;
    for (ll i = 0; i < n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        arr[i] = make_tuple(a, b, c);
        max1 = max(max1, b);
    }
    sort(arr.begin(), arr.end(), [](const tuple<ll, ll, ll>& a, const tuple<ll, ll, ll>& b) {
        if (get<1>(a) != get<1>(b)) {
            return get<1>(a) < get<1>(b); // Sort by get<1> first
        } else if (get<0>(a) != get<0>(b)) {
            return get<0>(a) < get<0>(b); // Then by get<0>
        } else {
            return get<2>(a) < get<2>(b); // Finally by get<2>
        }
    });
    vector<vector<ll>> dp(n + 1, vector<ll>(max1 + 1, -1));
    cout << dynamic(0,0,arr,dp) << endl;
    return 0;
}