#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
int mx=1e9;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int> > edge(m);
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        edge[i].push_back(x);
        edge[i].push_back(y);
        edge[i].push_back(z);
    }
    vector<int> dist(n+1,mx);
    dist[1]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int src=edge[j][0];
            int des=edge[j][1];
            int dst=edge[j][2];
            if(dist[src]!=mx&&dist[src]+dst<dist[des]){
                dist[des]=dist[src]+dst;
            }
        }
    }
    
}