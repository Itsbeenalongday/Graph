#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int>a[3000];
int dist[3000];
int check[3000];
int n;
queue<int>q;
// -2 는 사이클 존재, 사이클에 속하지 않은 정점
// -1은 사이클 아직 못찾음
// 0 ~ n-1은 사이클 존재, 사이클에 포함되므로 사이클의 시작 인덱스를 리턴
int dfs(int x,int px) {
	// 이미 방문 했으면 시작 인덱스 리턴
	if (check[x]==1) return x;
	// 아니면 방문 체크하고
	check[x] = 1;
	// 인접리스트 순회 시작
	for (int nx : a[x]) {
		// 왔던 길 되돌아 가는거 방지
		if (nx == px) continue;
		// search -> 방문여부 체크 안 하는 이유는 이전 정점과 다음 정점 비교하므로써 
		// continue 제어로 이미 방문 했다면 다른 후보를 찾으므로
		// check가 따로 필요 없다.
		int res = dfs(nx, x);
		// 사이클 존재, 사이클에 속하지 않은 정점
		if (res == -2) return -2;
		// 사이클 내부 순환
		if (res >= 0) {
			check[x] = 2;
			// 시작 노드 리턴한 경우인데 현재 위치가 시작노드임 => 사이클 순회 끝 
			// 시작 노드에 연결된 사이클에 속하지 않은 정점들을 골라내기 위해 
			// 시작노드 도착시 부터 -2리턴 시작
			// res는 임의의 노드의 리턴 값이고, 그 리턴 값은 -2아니면 시작 노드인데, -2는 이미 위에서 걸렀으므로
			// 여기서는 반드시 시작노드이고 그것이 현재 정점이라면, 시작노드이다.
			// dfs(사이클속하지않고 시작노드에 붙어있는노드,시작노드)는 -2를 리턴하게 만든다.
			if (x == res) return -2;
			// 시작 노드를 리턴한 것 중에 현재 정점이 시작 노드가 아니면 사이클에 속하는 정점이므로 시작 
			else return res;
		}
	}
	// 순환 중에 더이상 갈 곳 없으면 -1리턴
	return -1;
}
void bfs() {
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int nx : a[x]) {
			if (dist[nx] == -1) {
				q.push(nx);
				dist[nx] = dist[x] + 1;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int from, to;
		cin >> from >> to;
		from -= 1; to -= 1;
		a[from].push_back(to);
		a[to].push_back(from);
	}
	dfs(0, -1);
	for (int i = 0; i < n; ++i) {
		if (check[i] == 2) {
			dist[i] = 0;
			q.push(i);
		}
		else {
			dist[i] = -1;
		}
	}
	bfs();
	for (int i = 0; i < n; ++i) {
		cout << dist[i] << ' ';
	}
	cout << '\n';
	return 0;
}
