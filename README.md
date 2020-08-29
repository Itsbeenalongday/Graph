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
