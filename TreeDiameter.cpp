#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
pair<int,int> dfs(int node, int parent) {
    int maxDepth = 0;
    int farthestNode = node;
    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            pair<int, int> result = dfs(neighbor, node);
            if (result.second + 1 > maxDepth) {
                maxDepth = result.second + 1;
                farthestNode = result.first;
            }
        }
    }
    return make_pair(farthestNode, maxDepth);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    adj.resize(n);
    vector<int> visit(n,0);
    for(int i=0;i<n-1;i++){
        int parent,child;
        cin>>parent>>child;
        adj[parent-1].push_back(child-1);
        adj[child-1].push_back(parent-1);
    }
    pair<int,int> result = dfs(0, -1);
    int farthestNode = result.first;
    result = dfs(farthestNode, -1);
    int maxDiameter = result.second;
    cout<<maxDiameter<<endl;
}