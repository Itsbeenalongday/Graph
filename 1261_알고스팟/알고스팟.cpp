#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <deque>
#include <iostream>

using namespace std;
int n, m;
int map[105][105];
int wall[105][105];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

bool range_check(int x, int y) {
	if (x < 0) return false;
	if (x >= n) return false;
	if (y < 0) return false;
	if (y >= m) return false;
	return true;
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%1d", &map[i][j]);
			wall[i][j] = -1;
		}
	}
	deque<pair<int, int>> d;
	d.push_back(make_pair(0,0));
	wall[0][0] = 0;
	while (!d.empty()) {
		int x = d.front().first;
		int y = d.front().second;
		d.pop_front();
		for (int k = 0; k < 4; ++k) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (range_check(nx, ny)) {
				if (wall[nx][ny] == -1){
					if (!map[nx][ny]) {
						d.push_front(make_pair(nx, ny));
						wall[nx][ny] = wall[x][y];
					}
					else {
						d.push_back(make_pair(nx, ny));
						wall[nx][ny] = wall[x][y] + 1;
					}
				}
			}
		}
	}
	cout << wall[n - 1][m - 1] << '\n';
	return 0;
}