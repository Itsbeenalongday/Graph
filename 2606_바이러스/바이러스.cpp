#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int>a[100];
bool check[100];
int v,e;
int cnt;
void bfs(int node) {
	queue<int> q;
	check[node] = true;
	q.push(node);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int y : a[x]) {
			if (!check[y]) {
				q.push(y);
				check[y] = true;
				cnt+=1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> v >> e;
	for (int i = 0; i < e; ++i) {
		int from, to;
		cin >> from >> to;
		from -= 1; to -= 1;
		a[from].push_back(to);
		a[to].push_back(from);
	}
	bfs(0);
	cout << cnt << '\n';
	return 0;
}