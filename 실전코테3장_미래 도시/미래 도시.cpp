#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 1e9

int n, m; // 노드, 간선 개수

vector<vector<int>>graph(100, vector<int>(100, INF)); // 2차원 인접행렬

int main() {

    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;
        graph[from][to] = 1;
        graph[to][from] = 1;
    }

    int x, k;
    cin >> x >> k;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) graph[i][j] = 0; // 자기 자신에서 자기 자신으로 가는 비용은 0
        }
    }

    // floyd-whasher
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    int ans = graph[1][k] + graph[k][x]; // 어딜 거쳐서 어디로 간다 => 플로이드 워셔

    ans >= INF ? cout << -1 << '\n' : cout << ans << '\n';

    return 0;
}