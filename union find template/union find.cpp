#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 경로 압축 기법이 포함된 find 연산
int find_(vector<int>& parent,int x) {
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
    for (int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;
        union_(parent,a, b);
    }
    // 각 원소가 속한 집합의 루트
    for (int i = 1; i <= v; ++i) {
        cout << find_(parent,i) << ' ';
    }
    cout << '\n';
    // 부모 테이블
    for (int i = 1; i <= v; ++i) {
        cout << parent[i] << ' ';
    }
    cout << '\n';
    return 0;
}