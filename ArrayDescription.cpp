#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
vector<vector<int> > dp;
int dynamic(int i,int j,vector<int> &arr,int n,int m) {
    if(i<0 || i>=n){
        return 0;
    }
    if(j==0){
        if(arr[i]==0){
            return 1;
        }
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=0;
    if(arr[i]==0 || arr[i]==j){
        ans=(dynamic(i-1,j-1,arr,n,m)+dynamic(i+1,j-1,arr,n,m))%1000000007;
    }
    else{
        ans=dynamic(i-1,j-1,arr,n,m)%1000000007;
    }
    return dp[i][j]=ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    dp.resize(n,vector<int>(m,-1));
    int ans=0;
    for(int i=0;i<n;i++){
        ans=(ans+dynamic(i,m-1,arr,n,m))%1000000007;
    }
    cout<<ans<<endl;
}