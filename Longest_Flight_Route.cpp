#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
typedef long long ll;
list<ll> dfs(ll node, vector<vector<ll>> &adj, vector<bool> &visited, vector<list<ll>> &arr){
    if(node==adj.size()-1){
        list<ll> l;
        l.push_back(node);
        arr[node]=l;
        return l;
    }
    if(visited[node]){
        return arr[node];
    }
    visited[node] = true;
    list<ll> ans;
    for(auto it: adj[node]){
        list<ll> a = dfs(it, adj, visited, arr);
        if (a.size()!=0&&a.size() > ans.size()&& a.back() == adj.size()-1) {
            ans = std::move(a);
        }
    }
    ans.push_front(node);
    return arr[node]=ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> adj(n);
    vector<list<ll>> arr(n);
    vector<bool> visited(n, false);
    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        adj[x-1].push_back(y-1);
    }
    list<ll> res=dfs(0, adj, visited, arr);
    if(res.size()==0||res.back()!=n-1){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<res.size()<<endl;
    for(auto it: res){
        cout<<it+1<<" ";
    }
    cout<<endl;
    return 0;
}