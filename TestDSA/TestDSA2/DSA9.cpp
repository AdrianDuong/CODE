#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 1e9;

vector<pair<int, int>> adj[100005]; // danh sách kề
int dist[100005]; // khoảng cách ngắn nhất từ đỉnh S đến các đỉnh khác trên đồ thị

void dijkstra(int s) {
    priority_queue<pair<int, int>> pq;
    memset(dist, -1, sizeof(dist)); // khởi tạo khoảng cách ban đầu là -1 (không có đường đi từ S đến đỉnh đó)
    dist[s] = INF; // khoảng cách từ S đến chính nó là vô hạn
    pq.push({INF, s});
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d != dist[u]) continue; // nếu đã duyệt đỉnh u trước đó với khoảng cách tối ưu thì bỏ qua
        for (auto& v : adj[u]) {
            if (dist[v.first] < min(dist[u], v.second)) { // cập nhật khoảng cách tối ưu đến đỉnh v
                dist[v.first] = min(dist[u], v.second);
                pq.push({dist[v.first], v.first});
            }
        }
    }
}
int main() {
int n, m, q;
cin >> n >> m >> q;
vector<vector<pair<int, int>>> adj(n); // danh sách kề
for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u-1].push_back({v-1, w});
}

while (q--) {
    int s, t;
    cin >> s >> t;
    s--, t--;
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>> pq; // hàng đợi ưu tiên
    pq.push({0, s});
    dist[s] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = -pq.top().first;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (max(dist[u], w) < dist[v]) {
                dist[v] = max(dist[u], w);
                pq.push({-dist[v], v});
            }
        }
    }
    if (dist[t] == INF) cout << "-1\n";
    else cout << dist[t] << "\n";
}

return 0;
}
