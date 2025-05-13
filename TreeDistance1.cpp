#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
int maxDepth=0;
int terminalNode1=-1;
int terminalNode2=-1;
pair<int,int> dfs(int node,int parent){
    int maxDepth=0;
    int farthestNode=node;
    for(int i=0;i<adj[node].size();i++){
        if(adj[node][i]!=parent){
            pair<int,int> result=dfs(adj[node][i],node);
            if(result.second+1>maxDepth){
                maxDepth=result.second+1;
                farthestNode=result.first;
            }
        }
    }
    return make_pair(farthestNode,maxDepth);
}
void dfs2(int node,int parent,int depth,vector<int>& arr){
    arr[node]=depth;
    for(int i=0;i<adj[node].size();i++){
        if(adj[node][i]!=parent){
            dfs2(adj[node][i],node,depth+1,arr);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    adj.resize(n);
    for(int i=0;i<n-1;i++){
        int parent,child;
        cin>>parent>>child;
        adj[parent-1].push_back(child-1);
        adj[child-1].push_back(parent-1);
    }
    pair<int,int> result=dfs(0,-1);
    terminalNode1=result.first;
    result=dfs(terminalNode1,-1);
    terminalNode2=result.first;
    vector<int> arr1(n,0);
    vector<int> arr2(n,0);
    dfs2(terminalNode1,-1,0,arr1);
    dfs2(terminalNode2,-1,0,arr2);
    for(int i=0;i<n;i++){
        cout<<max(arr1[i],arr2[i])<<" ";
    }
    return 0;
}