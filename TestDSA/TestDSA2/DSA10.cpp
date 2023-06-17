#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define INF INT_MAX
const int MAXN = 1e5 + 5;
vector<pii> adj[MAXN];
int n, m;
int dist[MAXN], cnt[MAXN];

void dijkstra() {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    cnt[1] = 1;
    while(!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if(d > dist[u]) continue;
        for(auto v : adj[u]) {
            int next = v.first, w = v.second;
            if(dist[next] > dist[u] + w) {
                cnt[next] = cnt[u];
                dist[next] = dist[u] + w;
                pq.push({dist[next], next});
            } else if(dist[next] == dist[u] + w) {
                cnt[next] += cnt[u];
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    memset(dist, INF, sizeof(dist));
    memset(cnt, 0, sizeof(cnt));
    dijkstra();
    cout << dist[n] << " " << cnt[n] << endl;
    return 0;
}
