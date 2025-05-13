#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll res=LLONG_MAX;
ll INF=LLONG_MAX;
vector<ll> dijkstra(ll V, vector<vector<pair<ll, ll>>> &adj, int src){
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    vector<ll> dist(V, LLONG_MAX);
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while (!pq.empty()) {
        ll u = pq.top().second;
        if(dist[u] < pq.top().first) {
            pq.pop();
            continue;
        }
        pq.pop();
        for (auto it : adj[u]) {
            ll v = it.first;
            ll w = it.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    return dist;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll, ll>>> adj1(n), adj2(n);
    for (ll i = 0; i < m; i++) {
        ll x, y, z;
        cin >> x >> y >> z;
        adj1[x - 1].push_back(make_pair(y - 1, z));
        adj2[y - 1].push_back(make_pair(x - 1, z));
    }
    ll res=LLONG_MAX;
    vector<ll> dist1 = dijkstra(n, adj1, 0);
    vector<ll> dist2 = dijkstra(n, adj2, n-1);
    for (ll u = 0; u < n; u++) {
        for (auto [v, w] : adj1[u]) {
            if (dist1[u] != INF && dist2[v] != INF) {
                res = min(res, w / 2 + dist1[u] + dist2[v]);
            }
        }
    }
    cout<<res<<endl;
    return 0;
}