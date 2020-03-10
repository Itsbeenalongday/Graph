#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check[100000];
vector<int> a[100000];
vector<int> dfs_order;

void dfs(int node) {
	check[node] = true;
	dfs_order.push_back(node);
	for (int next : a[node]) {
		if (!check[next]) {
			dfs(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int from, to;
		cin >> from >> to;
		from -= 1; to -= 1;
		a[from].push_back(to);
		a[to].push_back(from);
	}
	vector<int>d(n);
	vector<int>order(n);
	for (int i = 0; i < n; ++i) {
		cin >> d[i];
		d[i] -= 1;
		order[d[i]] = i;
	}
	for (int i = 0; i < n; ++i) {
		sort(a[i].begin(), a[i].end(), [&](const int& from, const int& to) 
									   { 
											return order[from] < order[to]; 
									   });
	}
	dfs(0);
	dfs_order == d ? cout << 1 << '\n' : cout << 0 << '\n';
	return 0;
}