#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
bool flag=true;
void dfs(int idx, vector<vector<int> > &adj, vector<int> &color, int col) {
    if (color[idx] != 0) {
        flag = (color[idx] == col);
        return;
    }
    color[idx] = col;
    for (int i = 0; i < adj[idx].size(); i++) {
        if (!flag) return;
        dfs(adj[idx][i], adj, color, -col);
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
    vector<int> color(n,0);
    for (int i = 0; i < n; i++) {
        if (color[i]==0){
            dfs(i, adj, color, 1);
        }
    }

    if (!flag) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            cout << (color[i] == 1 ? 1 : 2) << " ";
        }
        cout << endl;
    }
    return 0;
}