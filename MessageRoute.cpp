#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
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
    queue<int> q;
    q.push(0);
    vector<int> baap(n);
    vis[0]=1;
    baap[0]=-1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int i=0;i<adj[node].size();i++){
            if(adj[node][i]==n-1){
                ans.push_back(n-1);
                int idx=node;
                while(baap[idx]!=-1){
                    ans.push_back(idx);
                    idx=baap[idx];
                }
                ans.push_back(0);
                cout<<ans.size()<<endl;
                for(int i=ans.size()-1;i>=0;i--){
                    cout<<ans[i]+1<<" ";
                }
                return 0;
            }
            if(!vis[adj[node][i]]){
                q.push(adj[node][i]);
                vis[adj[node][i]]=1;
                baap[adj[node][i]]=node;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}