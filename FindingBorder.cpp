#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.length();
    vector<int> dp(n,0);
    for(int i=0;i<n;i++){
        if(s.substr(0,i)==s.substr(n-i,n)){
            dp[i]=1;
        }
    }
    for(int i=1;i<n;i++){
        if(dp[i]>0)cout<<i<<" ";
    }
}