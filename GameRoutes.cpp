#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
int dfs(int idx,int dst,vector<vector<int> > &adj,vector<int> &count){
    if(idx==dst){
        return count[idx]=1;
    }
    if(count[idx]!=0)return count[idx];
    for (int i=0;i<adj[idx].size();i++) {
        count[idx]+=dfs(adj[idx][i],dst, adj,count);
        count[idx]%=1000000007;
    }
    return count[idx];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int> > adj(n);
    vector<int> count(n,0);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    vector<int> color(n,0);
    cout<<dfs(0,n-1,adj,count)<<endl;
}
