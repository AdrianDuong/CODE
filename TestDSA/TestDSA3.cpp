#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

void BFS(const vector<vector<int>>& graph, vector<bool>& visited, int start, vector<int>& connected_component) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    connected_component.push_back(start);
    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        for (int neighbor = 0; neighbor < graph.size(); ++neighbor) {
            if (graph[vertex][neighbor] == 1 && !visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                connected_component.push_back(neighbor);
            }
        }
    }
}
vector<vector<int>> findConnectedComponents(const vector<vector<int>>& graph) {
    vector<bool> visited(graph.size(), false);
    vector<vector<int>> connected_components;
    for (int vertex = 0; vertex < graph.size(); ++vertex) {
        if (!visited[vertex]) {
            vector<int> connected_component;
            BFS(graph, visited, vertex, connected_component);
            connected_components.push_back(connected_component);
        }
    }
    return connected_components;
}

int main() {
    ifstream inputFile("lienthong.txt");
    ofstream outputFile("lienthong.out");
    int N;
    inputFile >> N;
    vector<vector<int>> graph(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            inputFile >> graph[i][j];
        }
    }

    vector<vector<int>> connected_components = findConnectedComponents(graph);
    int num_components = connected_components.size();

    outputFile << "Number of connected components: " << num_components << endl;
    for (int i = 0; i < num_components; ++i) {
        outputFile << "Connected Component " << (i + 1) << ": ";
        for (int vertex : connected_components[i]) {
            outputFile << vertex << " ";
        }
        outputFile << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}

