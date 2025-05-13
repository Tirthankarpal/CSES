#include "bits/stdc++.h"
using namespace std;

const long long mx = 1e18;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, m;
    cin >> n >> m;
    vector<vector<pair<long long, long long> > > adj(n + 1);
    for (long long i = 0; i < m; i++) {
        long long x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back(make_pair(y,z));
    }
    vector<long long> dist(n + 1, mx);
    dist[1] = 0;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, greater<pair<long long, long long> > > pq;
    pq.push(make_pair(0, 1));
    while (!pq.empty()) {
        long long d = pq.top().first;
        long long node = pq.top().second;
        pq.pop();
        if (d > dist[node]) continue;
        for (auto edge : adj[node]) {
            long long next = edge.first;
            long long weight = edge.second;
            if (dist[node] + weight < dist[next]) {
                dist[next] = dist[node] + weight;
                pq.push(make_pair(dist[next], next));
            }
        }
    }

    for (long long i=1;i<=n;i++) {
        cout<<dist[i]<<" ";
    }
    cout << endl;
    return 0;
}