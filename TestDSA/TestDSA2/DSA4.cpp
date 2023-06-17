#include <iostream>
#include <cstring>
#include <queue>
#define MAX 1005
using namespace std;

int T, N, M;
int A[MAX][MAX];
int dist[MAX][MAX];

struct Node {
    int x, y;
};

bool isValid(int x, int y) {
    return (x >= 1 && x <= N && y >= 1 && y <= M);
}
int bfs() {
    queue<Node> q;
    Node start = {1, 1};
    q.push(start);
    memset(dist, -1, sizeof(dist));
    dist[1][1] = 0;

    while (!q.empty()) {
        Node curr = q.front();
        q.pop();

        int x = curr.x;
        int y = curr.y;

        if (x == N && y == M) {
            return dist[x][y];
        }
        if (isValid(x+1, y)) {
            int diff = A[x][y] - A[x+1][y];
            if (diff >= 0 && dist[x+1][y] == -1) {
                Node next = {x+1, y};
                q.push(next);
                dist[x+1][y] = dist[x][y] + 1;
            }
        }
        if (isValid(x, y+1)) {
            int diff = A[x][y] - A[x][y+1];
            if (diff >= 0 && dist[x][y+1] == -1) {
                Node next = {x, y+1};
                q.push(next);
                dist[x][y+1] = dist[x][y] + 1;
            }
        }

        if (isValid(x+1, y+1)) {
            int diff = A[x][y] - A[x+1][y+1];
            if (diff >= 0 && dist[x+1][y+1] == -1) {
                Node next = {x+1, y+1};
                q.push(next);
                dist[x+1][y+1] = dist[x][y] + 1;
            }
        }
    }
    return -1;
}
int main() {
    cin >> T;

    while (T--) {
        cin >> N >> M;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                cin >> A[i][j];
            }
        }

        int steps = bfs();
        cout << steps << endl;
    }
    return 0;
}
