# Graph

## 그래프 문제의 정의
* 문제의 여러가지 상황을 `그래프로 모델링`하고, `그래프 알고리즘을 적용`가능한 문제를 일컫는다.   

* Dynamic programming은 이런 이런 문제를 점화식(단계 간의 관계식), Brute-force은 이런 이런 방법을 이용하여 모든 경우의 수를 살펴보는것   

* 그래프 알고리즘은 조금 느낌이 틀리다. 그래프로 모델링이 필요하고 여기서 그에 맞는 그래프 알고리즘 (BFS, DFS 등)
  을 적용하는 것이기에 뭔가 특정하게 다이나믹프로그래밍이나 브루트포스처럼 방법론과는 조금 다르다.


## 그래프 이론
* 자료구조의 일종

* 정점(Node, Vertex)

* 간선(Edge) : 임의의 두 정점을 연결하는 `관계`

* G = (V,E)로 표현

* 경로(Path) : 하나의 정점에서 다른 정점까지 가는 간선의 `연속` => 계속 길이 있어야함(중간에 끊기면 안됨)

* 사이클(Cycle) : 정점 a에서 다시 a로 돌아오는 경로

* 단순 경로와 단순 사이클 : 경로 / 사이클에서 같은 정점을 두 번 이상 방문하지 않는 경로/사이클
  + 특별한 말이 없으면, 일반적으로 사용하는 경로와 사이클으 단순 경로/사이클을 일컫는다.

* 방향 있는 그래프(Directed graph)
  + A -> C 와 같이 간선에 방향이 있다.

* 방향 없는 그래프(Undirected graph)
  + A - C 와 같이 간선에 방향이 없다.
  + 양방향 그래프(Bidirection graph)라고도 한다.

* 간선 여러개
  + 두 정점 사이에 간선이 여러 개일 수도 있다.
  
* 루프(Loop)
  + 간선의 양 끝 점이 같은 경우가 있다.
  
* 가중치(Weight)
  + 간선에 가중치가 있는 경우
    - A에서 B로 이동하는 거리, 이동하는데 필요한 시간, 이동하는데 필요한 비용 등등등 ...
  + 가중치가 없는 경우에는 1이라고 생각하면 된다.

* 차수(Degree) 
  + 정점과 연결되어 있는 간선의 개수
  + 방향 그래프의 경우에는 in-degree, out-degree로 나누어서 차수를 계산한다.
  
  
## 그래프의 표현
1. 인접 행렬(adjacency-matrix)
  + 정점의 개수를 V라고 했을 때
  + V x V 크리의 이차원 배열을 이용
  + `A[i][j] ? (i->j 간선이 존재) 1 : 간선이 존재하지 않음 0`
  + 가중치가 있는 그래프에서는 1대신 가중치를 집어넣는다.

2. 인접 리스트(adjacency-list)
  + 리스트를 이용해서 구현한다.
  + A[i]와 연결된 정점을 리스트로 포함하고 있음
  + 리스트는 크기를 동적으로 변경할 수 있어야 한다.
    - C++ - vector / Java - ArrayList / Python - []
  + 링크드 리스트나 길이를 동적으로 변경할 수 있는 배열을 사용한다.
  + 가중치가 있는 그래프의 경우 정점과 간선의 가중치를 리스트로 포함 하고있음 순서쌍 형태 `vector<pair<int,int>>`
  
3. 인접 행렬 vs 인접 리스트
  + 구현
    - 인접 행렬
    ```cpp
    int adj_matrix[n][m] = {
      0, 1, 0, 1 . . .
      .  0
      .     0
      .        0
    }
    ```
    - 인접 리스트
    ```cpp
    vector<int> adj_list[n];
    cin >> from >> to;
    adj_list[from].push_back(to);
    adj_list[to].push_back(from);
    ```

## BFS, DFS

자주 사용되는 맵 형태인 이차원 배열에서의 코드와 인접 리스트나 행렬을 사용해야 할 때의 코드

+ BFS
  - 맵이 이차원 배열형태로 주어지는 경우
```cpp
bool check[n][m];
bool map[n][m];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

bool range_check(int x, int y) {
	bool ok = false;
	x >= 0 && x < n ? ok = (y >= 0 && y < m) : ok=ok;
	return ok;
}
void bfs(int x, int y){
  queue<pair<int,int>> q; check[x][y] = true; q.push(make_pair(x,y));
  while(!q.empty){
    x = q.front().first; y = q.front().second; q.pop();
    for(int k=0; k<4; ++k){
      int nx = x + dx[k]; int ny = y + dy[k];
      if(range_check(nx,ny)){
        if(map[nx][ny] == condition && !check[nx][ny]){
          check[nx][ny] = true;
          q.push(make_pair(nx,ny));
        }
      }
    }
  }
}
```
  - 맵이 인접 리스트의 형태로 주어지는 경우
```cpp
bool check[n];
vector<int> adj_list[n];

void bfs(int node){
  queue<int> q; check[node] = true; q.push(node);
  while(!q.empty){
    node = q.front(); q.pop();
    for(int i=0; i < (int)adj_list[next].size(); ++i){
      int next = a[node][i];
      if(!check[next]){
        check[next] = true;
        q.push(next);
      }
    }
  }
}
```

+ DFS
  - 맵이 이차원 배열형태로 주어지는 경우
```cpp
bool check[n][m];
bool map[n][m];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

bool range_check(int x, int y) {
	bool ok = false;
	x >= 0 && x < n ? ok = (y >= 0 && y < m) : ok=ok;
	return ok;
}

void dfs(int x, int y){
  check[x][y] = true;
  for(int k=0; k<4; ++k){
    int nx = x + dx[k];
    int ny = y + dy[k];
    if(range_check(nx,ny)){
      if(map[nx][ny] == condition && !check[nx][ny]){
        dfs(nx,ny);
      }
    }
  }
}
```
  - 맵이 인접 리스트의 형태로 주어지는 경우
```cpp
void dfs(int node) {
	check[node] = true;
	for (int i = 0; i < (int)a[node].size(); ++i) {
		int next = a[node][i];
		if (!check[next]) {
			dfs(next);
		}
	}
}
```

## 자주나오는 문제유형

1. 그룹화 하기

__예시__

```
11001
11100
00011

이런형태의 map에서 1은 육지를 의미하고, 0은 바다를 의미한다.
상하좌우로 이어져있는 육지끼리는 하나의 섬으로 간주한다.
이 때 섬의 총 개수는?
```

**해결책**
```cpp
int main(){
  for(int i=0; i<n; ++i){
    for(int j=0; j<m; ++j){
      if(map[i][j] == 1 && !check[i][j]){
        bfs(i,j,++group);
      }
    }
  }
}
```
idea는 simple하다.   
위와 같은 방법을 사용하면 서로 떨어진 섬끼리는 연결되지 않았기에, bfs/dfs가 수행된 횟수가 즉, 섬의 개수이다.   
탐색알고리즘은 서로 연결된 정점을 단 한번만 방문 알고리즘이라, 서로 연결이 안 된 정점끼리(즉, 다른 섬 끼리는)는 서로 다른 탐색알고리즘에서 색출된다.

2. 거리재기

__예시__
```
101010
111111
000001
111111
111111

와 같은 맵형태가 주어진다. 0은 벽이고, 1은 길을 의미한다.
(0,0)에서 출발하여 (n-1,m-1)로 가는 최소 거리를 구하시오.
단, 맵은 항상 출발점에서 끝점으로 갈 수 있게 주어진다.
```

**해결책**
최소거리 문제는 bfs로 해야한다.
dfs는 깊이 우선탐색이기에 최소 거리로 안 갈 확률이 다분하다.   
단순한 이진 트리를 떠올리고 넘버링은 왼쪽 서브트리부터 되있고,    
기준에 따르면 작은 순서부터 방문해야 한다고 가정해보자   
타겟은 트리의 제일 오른쪽에 위치한 점이다.   
기준에 따라 dfs는 왼쪽 서브트리부터 탐색하기에 아마도 제일 늦게 타겟에 도착할 것이다.   
이것은 우리가 원하는 것이 아니다.   
반면 bfs는 같은 깊이에서는 같은 거리로 측정되도록 코딩할 수 있다. 때문에 최단거리를 구할때는 bfs를 사용하는 것이 옳다.   

```cpp
void bfs(int x, int y){
  queue<pair<int,int>> q; map[x][y] = 1; q.push(make_pair(x,y));
  while(!q.empty){
    x = q.front().first; y = q.front().second; q.pop();
    for(int k=0; k<4; ++k){
      int nx = x + dx[k]; int ny = y + dy[k];
      if(range_check(nx,ny)){
        if(map[nx][ny] == condition && !check[nx][ny]){
          map[nx][ny] = map[x][y] + 1;
          q.push(make_pair(nx,ny));
        }
      }
    }
  }
}
```
idea는 simple하다.   
주어진 맵을 시작점으로부터 떨어진 거리로 바꿔가면서 탐색하면 최소거리를 구할 수 있다.   

## Shortest-path

**Dijkstra algorithm**

+ 정의
> graph에서 여러 개의 노드가 있을 때, 특정한 노드에서 출발하여 다른 노드로 가는 각각의 최단 경로를 구해주는 알고리즘

+ 분류
> greedy의 일좀

+ 제약사항
> 음의 가중치가 존재할 때 비정상 동작 가능

+ process

```
1. 출발노드를 설정

2. 최단 거리 테이블(각 노드에 대한 현재까지의 최단 거리) 초기화

3. 방문하지 않은 노드 중에서 최단 거리가 가장 짧은 노드를 선택한다.(Greedy approach)

4. 해당 노드를 거쳐 다른 노드로 가는 비용을 계산하여 최단 거리 테이블을 갱신

5. 위 과정에서 3, 4단게를 반복한다.

```

+ 특징
`한 단계당 하나의 노드에 대한 최단 거리를 확실히 찾는 것`

+ 구현방식
> 2가지 방법이 있다.

1. 순차탐색 + 갱신

+ 시간복잡도 O(N^2)

2. 힙 탐색 + 갱신

+ 시간복잡도 O(NlogN)

> Heap

<table>
    <thead>
        <th>우선순위 큐 구현 방식</th>
        <th>삽입 시간</th>
        <th>삭제 시간</th>
    </thead>
    <tbody>
        <tr>
            <td> 리스트 </td>
            <td> O(1) </td>
            <td> O(N) </td>
        </tr>
        <tr>
            <td> 힙 </td>
            <td> O(logN) </td>
            <td> O(logN) </td>
        </tr>
    </tbody>
</table>

Heap은 priority queue를 사용한다.   
최소값을 뽑아내야 하므로 최소 힙을 사용해야 한다.   
언어별로 힙 구현이 제각각이기 때문에 만약 최대 힙 기반으로 priority queue가 구현되어 있다면, 값을 *-1을 하는 방식을 통해 최소 힙으로 변경할 수 있다.   
다익스트라는 음수 가중치가 존재할 시 cycle이 발생할 수 있기 때문에, 힙에서만 음수를 사용하고 뽑은 후에 다시 * -1을 하여 원래대로 되돌려 놓는다.   

**코드**

> dijkstra algorithm

+ heap 미사용 코드

```cpp
#include <iostream>
#include <vector>

using namespace std;

#define INF 1e9

int n, m; // 노드, 간선 개수
int start; // 시작 노드

vector<bool>visited(100); // 노드가 100개 이하라고 가정함
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
```
+ heap 사용 코드

```cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 1e9

int n, m; // 노드, 간선 개수
int start; // 시작 노드

vector<bool>visited(100); // 노드가 100개 이하라고 가정함
vector<int>dist(100, INF);
vector<pair<int, int>>graph[100];

void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;
    while (!pq.empty()) {
        int d = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (dist[now] < d) continue; // 이미 처리된 노드면 무시
        for (pair<int, int> edge : graph[now]) {
            int cost = d + edge.second;
            if (cost < dist[edge.first]) {
                dist[edge.first] = cost;
                pq.push(make_pair(cost, edge.first));
            }
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
```

**Floyd - whasher 알고리즘**

`모든 지점에서 다른 모든 지점까지의 최단 경로를 모두 구해야하는 경우`

+ 시간복잡도
  O(N^3)

+ 특징
  1. 이차원 리스트에 최단거리 정보를 저장
  2. 다이나믹 프로그래밍을 이용
     - 최단거리를 메모이제이션한다 
     - 다시 계산하지 않는다 
     - 문제가 중복된다 
     - 긴 경로의 정답에 작은 경로의 정답이 포함된다

+ 알고리즘

  1. A에서 B로 가는 경로를 확인한다.
  2. 초기화 되어있는 경로보다 다른 노드를 거쳐가면 더 최단경로가 되는 경우 갱신한다.

+ 문제유형
`어디를 거쳐서 가야하는 최단경로`

```cpp
// a에서 출발해, k를 거쳐서 b로가는 것 vs 현재 상태에서 a에서 b로 가는 최단경로
fy[a][b] = min(fy[a][b],fy[a][k] + fy[k][b]);
```

**코드**
> Floyd - whasher algorithm

```cpp
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
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from][to] = cost;
    }

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

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (graph[i][j] == INF) cout << "INFINITY\n";
            else cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }
}
```

## Graph Theory

`연결되어있다` => 곧바로 그래프 알고리즘 상기

+ 서로소 집합

> 공통 원소가 없는 두 집합

**Union & find**

`서로소집합 자료구조`

+ 연산 
  + find: 부모를 찾는 연산, 즉 둘이 서로소 집합인지 아닌지 판별
  + union: 서로소 집합 두개를 합치는 연산

+ 시간복잡도
  - 노드가 v개이고, 최대 v-1개의 연산과(루트 제외 모든 노드 한번씩 합친다), m번의 find연산을 할 때
  - O(v + mlog2-m/v(v))

+ 활용
  - 무방향 그래프에서 사이클 판별
  - 루트 노드가 다르다면 두 노드에 대해 union연산을 수행
  - 루트 노드가 서로 같다면 cycle이 발생(루트가 같은데 또 합치려고 하는 것이므로)
  - 방향그래프에서 사이클 판별은 dfs로 가능하다.

+ 코드

```cpp
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
```

**kruskal algorithm**

+ 신장 트리
  `하나의 그래프가 있을 때 모든 노드를 포함하면서 사이클이 존재하지 않는 부분 그래프`

+ 응용
  `모든 도시를 연결할 때 최소의 비용으로 연결하고 싶다`

+ 특징
  + 그리디 알고리즘
  + 가장 짧은 것부터 고른다.
  + 트리는 간선의 개수가 노드의 개수-1개 이다.

+ 알고리즘
  1. edge를 비용에 따라 오름차순으로 정렬
  2. 간선을 하나씩 확인하며 사이클을 발생시키는지 확인
   - 발생하면 트리에 넣지말고, 발생하지 않으면 넣는다.
  3. 모든 간선에 대해 2번의 과정을 반복한다.

+ 시간 복잡도
  - 간선의 개수 e 
  - O(eloge), 정렬이 필요하기 때문

+ 코드

```cpp
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
```

**topology sort**

`일련의 작업을 차례대로 수행해야 할 때 사용한다`

+ 정의

> 방향 그래프의 모든 노드를 방향성에 거스르지 않도록 순서대로 나열하는 것

+ 알고리즘
  1. 진입차수가 0인 노드를 큐에 삽입한다.
  2. 큐가 빌 때까지 다음의 과정을 반복한다.
     1. 큐에서 원소를 꺼내 해당 노드에서 출발하는 간선을 그래프에서 제거
     2. 새롭게 진입차수가 0이 된 노드를 큐에 넣는다.

+ 특징
  + 모든 원소를 방문하기 전 큐가 빈다면 사이클이 존재한다.
  + 사이클이 존재하는 경우 어떠한 원소도 큐에 들어가지 못하기 때문
  + 한 단계에서 큐에 새롭게 들어가는 원소가 2개 이상인 경우가 있다면, 답은 여러개 존재한다.

+ 시간복잡도
  + 노드의 개수 v, 간선의 개수 e 일 때,
  + O(v + e) 

+ 코드

```cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int v, e;
vector<int> indegree(101);
vector<int> adj_list[101];
vector<int> result;

void topology_sort() {
	queue<int> q;
	for (int i = 1; i <=v; ++i) {
		if (!indegree[i]) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int now = q.front(); q.pop();
		result.push_back(now);
		for (int next : adj_list[now]) {
			indegree[next] -= 1;
			if (!indegree[next]) {
				q.push(v);
			}
		}
	}
}

int main() {
	cin >> v >> e;
	for (int i = 0; i < e; ++i) {
		int from, to;
		cin >> from >> to;
		adj_list[from].push_back(to);
		indegree[to] += 1;
	}
	topology_sort();
	for (int i : result) {
		cout << i << ' ';
	}
	cout << '\n';
	return 0;
}
```
