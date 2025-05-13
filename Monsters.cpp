#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool flag=false;
void dfs(ll node,vector<vector<ll>>& adj,vector<bool>& visited,ll count,unordered_set<int>& s){
    if(flag){
        return;
    }
    if(s.find(node)!=s.end()){
        flag=true;
        return;
    }
    visited[node]=true;
    for(int i=0;i<adj[node].size();i++){
        if(!visited[adj[node][i]]){
            dfs(adj[node][i],adj,visited,count,s);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin>>n>>m;
    vector<vector<ll> > adj(n);
    vector<bool> visited(n, false);
    vector<vector<ll>> edge(m,vector<ll>(3,0));
    vector<ll> dis(n, LLONG_MIN);
    unordered_set<int> s;
    for (ll i = 0; i < m; i++) {
        ll x,y,z;
        cin>>x>>y>>z;
        edge[i][0]=x-1;
        edge[i][1]=y-1;
        edge[i][2]=z;
    }
    dis[0]=0;
    ll result=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            int u=edge[j][0];
            int v=edge[j][1];
            int w=edge[j][2];
            if(dis[u]!=LLONG_MIN && dis[v]<dis[u]+w){
                dis[v]=dis[u]+w;
            }
        }
    }
    result=dis[n-1];
    for(int i=0;i<m;i++){
        int u=edge[i][0];
        int v=edge[i][1];
        int w=edge[i][2];
        if(dis[u]!=LLONG_MIN && dis[v]<dis[u]+w){
            dis[v]=dis[u]+w;
            s.insert(v);
        }
    }
    for(int i=0;i<m;i++){
        int u=edge[i][0];
        int v=edge[i][1];
        adj[v].push_back(u);
    }
    dfs(n-1,adj,visited,0,s);
    if(flag){
        cout<<-1<<endl;
        return 0;
    }
    else{
        cout<<result<<endl;
    }
    return 0;
}