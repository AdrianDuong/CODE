#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 300;
int n, m, ans;

vector<int> G[MAXN];
int dfn[MAXN], low[MAXN], vis[MAXN], iscut[MAXN];
int dfs_cnt;

void init() {
    ans = -1;
    dfs_cnt = 0;
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(vis, 0, sizeof(vis));
    memset(iscut, 0, sizeof(iscut));
    for (int i = 1; i <= n; i++)
        G[i].clear();
}

void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++dfs_cnt;
    vis[u] = 1;
    int child = 0;
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            child++;
            if (low[v] >= dfn[u]) {
                if (u != fa || child > 1)
                    iscut[u] = 1;
            }
        }
        else if (dfn[v] < dfn[u] && v != fa)
            low[u] = min(low[u], dfn[v]);
    }
}

int dfs(int u, int fa) {
    vis[u] = 1;
    int res = 1;
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (v == fa || iscut[v])
            continue;
        res += dfs(v, u);
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        init();
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        for (int i = 1; i <= n; i++) {
            if (!dfn[i]) {
                tarjan(i, i);
            }
        }

        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && !iscut[i]) {
                int cnt = dfs(i, i);
                if (cnt == n - 1) {
                    ans = i;
                    break;
                }
            }
        }
        if (ans == -1)
            cout << 0 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
