#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

const int N = 1e5 + 5;
const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int T, n, xa, ya, xb, yb;
vector<pair<int, int>> lines[N];
queue<pair<int, int>> q;
int dist[N];
bool vis[N];

int get_dist(pair<int, int> a, pair<int, int> b) {
    if (a.x == b.x) return abs(a.y - b.y);
    else return abs(a.x - b.x);
}

void bfs() {
    while (!q.empty()) {
        int u = q.front().x, steps = q.front().y;
        q.pop();
        for (auto line : lines[u]) {
            for (int i = 0; i < 8; i++) {
                int vx = line.x + dx[i], vy = line.y + dy[i];
                if (vx >= xa && vx <= xb && vy >= ya && vy <= yb) {
                    int v = (vx - xa) * (yb - ya + 1) + (vy - ya);
                    if (!vis[v]) {
                        vis[v] = true;
                        dist[v] = steps + get_dist(make_pair(line.x, line.y), make_pair(vx, vy));
                        q.push(make_pair(v, dist[v]));
                    } else if (dist[v] == steps + get_dist(make_pair(line.x, line.y), make_pair(vx, vy))) {
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> xa >> ya >> xb >> yb;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x, y1, y2;
            cin >> x >> y1 >> y2;
            for (int j = y1; j <= y2; j++) {
                lines[x - xa].push_back(make_pair(x, j));
            }
        }
        memset(dist, 0x3f, sizeof dist);
        memset(vis, false, sizeof vis);
        dist[0] = 0;
        q.push(make_pair(0, 0));
        bfs();
        cout << dist[(xb - xa) * (yb - ya + 1) + (yb - ya)] << endl;
        for (int i = 0; i < N; i++) {
            lines[i].clear();
        }
    }
    return 0;
}
