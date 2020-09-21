#include <iostream>
#include <vector>

using namespace std;

#define INF 1e9

int n, m; // 노드, 간선 개수
int start; // 시작 노드

vector<bool>visited(100);
vector<int>dist(100, INF);
vector<pair<int, int>>graph[100];

int get_smallest_node() {
    int min_value = INF;
    int index = 0;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] < min_value && !visited[i]) {
            min_value = dist[i];
            index = i; // 현 노드와 가장 가까운 노드
        }
    }
    return index;
}

void dijkstra(int start) {
  
    dist[start] = 0;
    visited[start] = true;
    for (pair<int, int> edge : graph[start]) {
        dist[edge.first] = edge.second; // first로 가는 거리 second, direct path로 갱신
    }
    for (int i = 0; i < n - 1; ++i) {
        int now = get_smallest_node();
        visited[now] = true;
        for (pair<int, int> edge : graph[now]) {
            int cost = dist[now] + edge.second; // 현재저장된 now까지의 거리(현재 선택된 노드) + 선택된 노드와 다른 노드들과의 거리를 본다.
            cost < dist[edge.first] ? dist[edge.first] = cost : dist[edge.first] = dist[edge.first];
        }
    }
}

int main() {
    cin >> n >> m;
    cin >> start;
    for (int i = 0; i < m; ++i) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back(make_pair(to, cost));
    }

    dijkstra(start);

    for (int i = 1; i <= n; ++i) {
        if (dist[i] == INF) cout << "INFINITY\n";
        else cout << dist[i] << '\n';
    }
}