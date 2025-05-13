#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> edge(m,vector<ll>(3,0));
    vector<vector<ll>> adj(n);
    vector<ll> dis(n, LLONG_MAX);
    for(int i=0;i<m;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        edge[i][0]=x-1;
        edge[i][1]=y-1;
        edge[i][2]=z;
        adj[x-1].push_back(y-1);
    }
    dis[0]=0;
    vector<ll> parent(n, -1);
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            int u=edge[j][0];
            int v=edge[j][1];
            int w=edge[j][2];
            if(dis[u]!=LLONG_MIN && dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                parent[v]=u;
            }
        }
    }
    ll node=-1;
    bool flag=false;
    for(int i=0;i<m;i++){
        int u=edge[i][0];
        int v=edge[i][1];
        int w=edge[i][2];
        if(dis[u]!=LLONG_MAX && dis[v]>dis[u]+w){
            dis[v]=dis[u]+w;
            node=v;
            flag=true;
        }
    }
    if(!flag){
        cout<<"NO"<<endl;
        return 0;
    }
    else{
        vector<ll> result;
        ll num=node;
        result.push_back(node);
        while(parent[node]!=-1){
            result.push_back(node);
            ll temp=parent[node];
            parent[node]=-1;
            node=temp;
        }
        result.push_back(node);
        reverse(result.begin(), result.end());
        cout<<"YES"<<endl;
        for(int i=0;i<result.size();i++){
            cout<<result[i]+1<<" ";
        }
        cout<<endl;
    }
}