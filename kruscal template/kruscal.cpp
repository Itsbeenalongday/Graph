#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct edge {
    int cost;
    int from;
    int to;
}edge;
// 경로 압축 기법이 포함된 find 연산
int find_(vector<int>& parent, int x) {
    if (parent[x] != x) { // 루트가 아니라면,
        parent[x] = find_(parent, parent[x]); // 재귀적으로 부모 찾기
    }
    return parent[x];
    // return x;를 하게될 경우, 경로 압축 기법 미사용 코드 루트가 아닌 애들은 자기자신의 곧바로 있는 부모노드로 연결
}

void union_(vector<int>& parent, int a, int b) {
    a = find_(parent, a);
    b = find_(parent, b);
    a < b ? parent[b] = a : parent[a] = b;
}

int main() {
    int v, e;
    cin >> v >> e; // 노드와 간선의 개수입력
    vector<int> parent(v + 1, 0);
    for (int i = 1; i <= v; ++i) {
        parent[i] = i; // 부모를 자기자신으로 초기화
    }
    vector<edge> edges;
    for (int i = 0; i < e; ++i) {
        int cost, from, to;
        cin >> from >> to >> cost;
        edges.push_back({ cost, from, to });
    }
    int result = 0;
    sort(edges.begin(), edges.end(), [](edge a, edge b) {
        return a.cost < b.cost;
    });
    for (edge e : edges) {
        int cost = e.cost;
        int from = e.from;
        int to = e.to;
        if (find_(parent, from) != find_(parent, to)) { // cycle 체크
            union_(parent, from, to);
            result += cost;
        }
    }
    cout << result << '\n';
    return 0;
}