#include <iostream>
#include <queue>

using namespace std;

int map[100][100];
int g[100][100];
int dist[100][100];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, cnt;
bool range_check(int x, int y) {
	if (x < 0) return false;
	if (x >= n) return false;
	if (y < 0) return false;
	if (y >= n) return false;
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (map[i][j] == 1 && g[i][j] == 0) {
				queue<pair<int, int>>q;
				q.push(make_pair(i, j));
				g[i][j] = ++cnt;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int k = 0; k < 4; ++k) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (range_check(nx,ny)) {
							if (map[nx][ny] == 1 && g[nx][ny] == 0) {
								g[nx][ny] = cnt;
								q.push(make_pair(nx, ny));
							}
						}
					}
				}
			}
		}
	}
	// starting point!
	queue<pair<int, int>> q;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			dist[i][j] = -1;
			if (map[i][j]) {
				q.push(make_pair(i, j));
				dist[i][j] = 0;
			}
		}
	}
	// 섬 확장
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; ++k) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (range_check(nx, ny)) {
				if (dist[nx][ny] == -1) {
					g[nx][ny] = g[x][y];
					dist[nx][ny] = dist[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	// 답 구하기
	int ans = -1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < 4; ++k) {
				int x = i + dx[k];
				int y = j + dy[k];
				if (range_check(x, y)) {
					if (g[x][y] != g[i][j]) {
						if (ans == -1 || ans > dist[i][j] + dist[x][y]) {
							ans = dist[i][j] + dist[x][y];
						}
					}
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}