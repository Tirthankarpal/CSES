#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
vector<vector<int> > dp;
int dynamic(int i,int j,string &s,string &t){
    if(i==s.length()||j==t.length()){
        return max(s.length()-i,t.length()-j);
    }
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j])return dp[i][j]=dynamic(i+1,j+1,s,t);
    else{
        return dp[i][j]=min(1+dynamic(i+1,j+1,s,t),min(1+dynamic(i+1,j,s,t),1+dynamic(i,j+1,s,t)));
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s,t;
    cin>>s>>t;
    dp=vector<vector<int> >(s.length()+1,vector<int>(t.length()+1,-1));
    cout<<dynamic(0,0,s,t)<<endl;
    return 0;
}