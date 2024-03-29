#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N, S, connected;
int mt[100][100];
vector<vector<int>> G;

void DfsTree(int s) {
    vector<pair<int, int>> tree;
    vector<bool> vs(N + 1, false);

    stack<int> st;
    st.push(s);
    vs[s] = true;

    while (!st.empty()) {
        int u = st.top();
        st.pop();
        for (int v : G[u]) {
            if (!vs[v]) {
                tree.push_back({min(u, v), max(u, v)});
                st.push(u);
                st.push(v);
                vs[v] = true;
                break;
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (!vs[i]) {
            connected = false;
            return;
        }
    }
    connected = true;
    cout << "Stack DFS tree\n";
    for (auto i : tree) {
        cout << i.first << " " << i.second << "\n";
    }
}

int main() {
    cin >> N >> S;
    G.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> mt[i][j];
            if (mt[i][j] == 1) {
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }
    DfsTree(S);
    if (!connected) {
        cout << "No spanning tree";
        return 0;
    }
}