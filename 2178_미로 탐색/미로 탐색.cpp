# define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;
int maze[100][100];
bool check[100][100];
int dist[100][100];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n, m;

bool range_check(int x, int y) {
	if (x < 0) return false;
	if (x >= n) return false;
	if (y < 0) return false;
	if (y >= m) return false;
	return true;
}
void bfs(int x, int y) {
	dist[0][0] = 1;
	queue<pair<int, int>> q; q.push(make_pair(x, y)); check[x][y] = true;
	while (!q.empty()) {
		x = q.front().first; y = q.front().second; q.pop();
		for (int k = 0; k < 4; ++k) {
			int nx = x + dx[k]; int ny = y + dy[k];
			if (range_check(nx, ny)) {
				if (maze[nx][ny] == 1 && check[nx][ny] == 0) {
					q.push(make_pair(nx, ny)); check[nx][ny] = true;
					dist[nx][ny] = dist[x][y] + 1;
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
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (check[i][j] == false && maze[i][j] == 1) {
				bfs(i, j);
			}
		}
	}
	cout << dist[n-1][m-1] << '\n';
	return 0;
}
