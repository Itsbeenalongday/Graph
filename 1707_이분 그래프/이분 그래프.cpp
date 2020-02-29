#include <iostream>
#include <vector>

using namespace std;

vector<int> a[20001];
int check[20001];

bool dfs(int node, int group) {
	check[node] = group;
	for (int i = 0; i < (int)a[node].size(); ++i) {
		int next = a[node][i];
		if (!check[next]) {
			if (!dfs(next, 3 - group)) {
				return false;
			}
		}
		else if (check[next] == check[node]) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int v, e;
		cin >> v >> e;
		// testcase 여러개이기 때문에 초기화 필요
		for (int i = 1; i <= v; ++i) {
			a[i].clear();
			check[i] = 0;
		}
		for (int i = 0; i < e; ++i) {
			int from, to;
			cin >> from >> to;
			a[from].push_back(to);
			a[to].push_back(from);
		}
		bool ok = true;
		for (int i = 1; i <= v; ++i) {
			if (!check[i]) {
				if (!dfs(i, 1)) {
					ok = false;
				}
			}
		}
		ok ? cout << "YES" << '\n' : cout << "NO" << '\n';
	}
	return 0;
}