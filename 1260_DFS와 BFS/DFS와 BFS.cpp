#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

bool check[1001];
vector<int> a[1001];

/* Not using recursive in dfs

	void dfs(int node){
		stack<pair<int,int>>s;
		s.push(make_pair(node,0));
		check[node] = true;
		// pair의 second는 해당 정점에서 방문한 인접리스트의 수
		cout << node << ' ';
		while(!s.empty()){
		  int node = s.top().first;
		  int start = s.top().second;
		  s.pop();
		  for(int i =start; i<a[node].size(); ++i){
			int next = a[node][i];
			if(!check[next]){
			 cout << next << ' ';
			 // i가 size초과 되면
			 s.push(make_pair(node,i+1);
			 // next의 인접리스트를 돌기 시작
			 s.push(make_pair(next,0);
			 break;
			}
		  }
		}
	}
*/

void dfs(int node) {
	check[node] = true;
	cout << node << ' ';
	for (int i = 0; i < (int)a[node].size(); ++i) {
		int next = a[node][i];
		if (!check[next]) {
			dfs(next);
		}
	}
}

void bfs(int start) {
	queue<int> q;
	memset(check, false, sizeof(check));
	check[start] = true; q.push(start);
	while (!q.empty()) {
		int node = q.front(); q.pop();
		cout << node << ' ';
		for (int i = 0; i < (int)a[node].size(); ++i) {
			int next = a[node][i];
			if (!check[next]) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m, start;
	cin >> n >> m >> start;
	for (int i = 0; i < m; ++i) {
		int from, to;
		cin >> from >> to;
		a[from].push_back(to);
		a[to].push_back(from);
	}
	// 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문
	// 이것을 수행하기 위해 인접리스트를 sorting 시키면 된다.
	for (int i = 1; i <= n; ++i) {
		sort(a[i].begin(), a[i].end());
	}
	dfs(start);
	cout << '\n';
	bfs(start);
	cout << '\n';
	return 0;
}