#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int>a[1000];
bool check[1000];
int connected = 0;

void bfs(int start) {
	if (!check[start]) {
		connected += 1;
	}
	queue<int> q; q.push(start);
	check[start] = true;
	while (!q.empty()) {
		int node = q.front(); q.pop();
		for (int i = 0; i < (int)a[node].size(); ++i) {
			int next = a[node][i];
			if (!check[next]) {
				check[next] = true; q.push(next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int from, to;
		cin >> from >> to;
		a[from].push_back(to);
		a[to].push_back(from);
	}

	for (int i = 1; i <= n; ++i) {
		bfs(i);
	}
	cout << connected << '\n';
	return 0;
}