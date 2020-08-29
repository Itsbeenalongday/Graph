#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>

using namespace std;
int n, m;
int maze[201][201];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1,-1,0,0 };

bool range_check(int x, int y) {
	bool ok = false;
	x >= 0 && x < n ? ok = (y >= 0 && y < m) : ok=ok;
	return ok;
}

void bfs(int x, int y) {
	queue<pair<int, int>> q; q.push(make_pair(x, y)); maze[x][y] = 2;
	while (!q.empty()) {
		x = q.front().first; y = q.front().second; q.pop();
		for (int k = 0; k < 4; ++k) {
			int nx = x + dx[k]; int ny = y + dy[k];
			if (nx == n-1 && ny == m-1) {
				maze[nx][ny] = maze[x][y] + 1;
				return;
			}
			if (range_check(nx, ny)) {
				if (maze[nx][ny]==1) {
					maze[nx][ny] = maze[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%1d", &maze[i][j]);
		}
	}
	bfs(0, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%d", maze[i][j]);
		}
		cout << '\n';
	}
	maze[n - 1][m - 1] -= 1;
	cout << maze[n-1][m-1] << '\n';
	return 0;
}