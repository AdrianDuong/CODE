#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300;

vector<int> graph[MAXN+1]; 
bool visited[MAXN+1];       

void dfs(int u) 
{
    visited[u]= true;
    for (int i=0; i<graph[u].size();i++) 
    {
        int v= graph[u][i];
        if (!visited[v]) 
        {
            dfs(v);
        }
    }
}

int main() 
{
    int n, m, x;
    cin >>n>>m>>x;
    for (int i= 0; i < m; i++) 
    {
        int u, v;
        cin>>u> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    memset(visited, false, sizeof(visited));

    dfs(x);
    bool found= false;
    for (int i = 1; i <= n; i++) 
    {
        if (!visited[i] && i != x) 
        {
            cout << i << endl;
            found = true;
        }
    }
    if (!found) 
    {
        cout << 0 << endl;
    }
    return 0;
}
