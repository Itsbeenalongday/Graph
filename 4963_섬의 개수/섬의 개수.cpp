#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dx[] = { 0,0,1,-1,1,1,-1,-1 };
int dy[] = { 1,-1,0,0,1,-1,1,-1 };
int map[100][100];
int check[100][100];
int w, h;

// x가 행, y가 열
bool range_check(int x, int y) {
	if (x < 0) return false;
	else if (x >= h) return false;
	else if (y < 0) return false;
	else if (y >= w) return false;
	return true;
}

void bfs(int x, int y, int group) {
	queue<pair<int, int>>q; q.push(make_pair(x, y)); check[x][y] = group;
	while (!q.empty()) {
		x = q.front().first; y = q.front().second; q.pop();
		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k]; int ny = y + dy[k];
			if (range_check(nx, ny)) {
				if (map[nx][ny] == 1 && check[nx][ny] == 0) {
					q.push(make_pair(nx, ny)); check[nx][ny] = group;
				}
			}
		}
	}
}

int main() {
	while (true) {
		cin >> w >> h;
		if (!w && !h) {
			break;
		}
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				scanf("%1d", &map[i][j]);
				check[i][j] = 0;
			}
		}
		int group = 0;
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				if (map[i][j] == 1 && check[i][j] == 0) {
					bfs(i, j, ++group);
				}
			}
		}
		cout << group << '\n';
	}
	return 0;
}