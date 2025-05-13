#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, total = 0, ans = INT_MAX;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++){
        cin >> arr[i];
        total += arr[i];
    }
    for (ll i = 0;i< (1<<n); i++){
        ll s = 0;
        for (ll j = 0; j < n; j++){
            if (i & 1 << j)
                s += arr[j];
        }
        ll curr = abs((total - s) - s);
        ans = min(ans, curr);
    }
    cout << ans;
    return 0;
}