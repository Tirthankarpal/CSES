#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
void bfs(int idx,vector<vector<int> > &adj,vector<int> &vis){
    queue<int> q;
    q.push(idx);
    vis[idx]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int i=0;i<adj[node].size();i++){
            if(!vis[adj[node][i]]){
                q.push(adj[node][i]);
                vis[adj[node][i]]=1;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int> > adj(n);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    vector<int> vis(n,0);
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            ans.push_back(i);
            bfs(i,adj,vis);
        }
    }
    cout<<ans.size()-1<<endl;
    for(int i=1;i<ans.size();i++){
        cout<<ans[0]+1<<" "<<ans[i]+1<<endl;
    }
    return 0;
}