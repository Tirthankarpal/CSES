#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dynamic(ll i,ll j,vector<ll>& a,vector<ll>& b) {
    if(i >= a.size() || j >= b.size()) {
        return 0;
    }
    if(a[i]==b[j]){
        cout << a[i] << " ";
        return 1+dynamic(i+1,j+1,a,b);
    }
    else return max(dynamic(i+1,j,a,b),dynamic(i,j+1,a,b));
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
    vector<vector<ll>> dp(m+1,vector<ll>(n+1,0));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(b[i-1]==a[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    vector<ll> ans;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (b[i - 1] == a[j - 1]) {
            ans.push_back(a[j - 1]); 
            i--;
            j--;
        } 
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--; 
        } 
        else {
            j--;
        }
    }
    cout << dp[m][n] << endl;
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=m;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for(int i=ans.size()-1;i>=0;i--){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}