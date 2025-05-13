#include "bits/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using namespace std;
ll dynamic(int i,int j,vector<ll> &arr,vector<vector<ll> > &dp) {
    if(i>j){
        return 0;
    }
    if(j-i==1){
        return max(arr[i],arr[j]);
    }
    if(i==j){
        return arr[i];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    ll left=arr[i]+min(dynamic(i+2,j,arr,dp),dynamic(i+1,j-1,arr,dp));
    ll right=arr[j]+min(dynamic(i,j-2,arr,dp),dynamic(i+1,j-1,arr,dp));
    return dp[i][j]=max(left,right);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    vector<vector<ll> > dp(n,vector<ll>(n,-1));
    cout<<dynamic(0,n-1,arr,dp)<<endl;
}