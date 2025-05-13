#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> findOrder(ll n, vector<vector<ll> >& pre) {
    vector<ll> inorder(n, 0);
    vector<vector<ll> > adj(n);
    for (ll i = 0; i < pre.size(); i++) {
        inorder[pre[i][0]]++;
        adj[pre[i][1]].push_back(pre[i][0]);
    }
    queue<ll> q;
    for (ll i = 0; i < n; i++) {
        if (inorder[i] == 0) q.push(i);
    }
    vector<ll> arr;
    while (!q.empty()) {
        ll ele = q.front();
        q.pop();
        for (ll j = 0; j < adj[ele].size(); j++) {
            inorder[adj[ele][j]]--;
            if (inorder[adj[ele][j]] == 0) q.push(adj[ele][j]);
        }
        arr.push_back(ele);
    }

    if (arr.size() != n) {
        vector<ll> empty;
        return empty;
    }
    return arr;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<vector<ll> > pre(m, vector<ll>(2));
    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >>a >>b;
        pre[i][0] = a - 1;
        pre[i][1] = b - 1;
    }
    vector<ll> order = findOrder(n, pre);
    if (order.empty()) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (ll i =order.size()-1; i>=0; i--) {
            cout << order[i]+1 << " ";
        }
        cout << endl;
    }
    return 0;
}