#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAXN 100005
#define INF 1e9

using namespace std;

int n, m;
vector<pair<int,int>> g[MAXN];
int dist[MAXN];
int cnt[MAXN];

void dijkstra(int start) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    memset(dist, INF, sizeof(dist));
    dist[start] = 0;
    pq.push(make_pair(0, start));
    cnt[start] = 1;

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i].first;
            int w = g[u][i].second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u];
                pq.push(make_pair(dist[v], v));
            } else if (dist[u] + w == dist[v]) {
                cnt[v] += cnt[u];
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back(make_pair(v, c));
        g[v].push_back(make_pair(u, c));
    }

    dijkstra(1);

    cout << dist[n] << " " << cnt[n] << endl;

    return 0;
}
