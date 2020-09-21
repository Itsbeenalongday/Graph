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