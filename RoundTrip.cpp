#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> result;
int resultnode=-1;
void dfs(ll node,vector<vector<ll>>& adj,vector<bool>& visited,vector<ll>& ans,vector<ll>& mp){
    if(visited[node]){
        if(ans.size()-mp[node]>2){
            for(int i=mp[node];i<ans.size();i++){
                result.push_back(ans[i]);
            }
            result.push_back(node);
            resultnode=node;
        }
        return;
    }
    ans.push_back(node);
    visited[node] = true;
    mp[node]=ans.size()-1;
    for(int i=0;i<adj[node].size();i++){
        if (adj[node][i] != (ans.size() > 1 ? ans[ans.size() - 2] : -1)) { //to check if we are revisiting its parent
            dfs(adj[node][i],adj,visited,ans,mp);
            if(resultnode!=-1){
                return;
            }
        }
    }
    ans.pop_back();
    mp[node]=-1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin>>n>>m;
    vector<vector<ll> > adj(n);
    vector<bool> visited(n, false);
    for (ll i = 0; i < m; i++) {
        ll x,y;
        cin>>x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    vector<ll> mp(n, -1);
    vector<ll> ans;
    for(int i=0;i<n;i++){
        if(!visited[i]&&resultnode==-1){
            dfs(i,adj,visited,ans,mp);
            if(resultnode!=-1){
                break;
            }
        }
    }
    if(result.size()==0){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<result.size()<<endl;
    for(int i=0;i<result.size();i++){
        cout<<result[i]+1<<" ";
    }
    return 0;
}