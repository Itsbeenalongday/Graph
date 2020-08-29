#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, m;
int icebox[1000][1000];

int dx[] = {0, 0, 1, -1};
int dy[] = { 1,-1,0,0 };

bool range_check(int x, int y) {
	if (x < 0) return false;
	else if (x >= n) return false;
	else if (y < 0) return false;
	else if (y >= m) return false;
	return true;
}

void bfs(int x, int y, int group) {
	queue<pair<int, int>>q; q.push(make_pair(x, y)); icebox[x][y] = group;
	while (!q.empty()) {
		x = q.front().first; y = q.front().second; q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k]; int ny = y + dy[k];
			if (range_check(nx, ny)) {
				if (!icebox[nx][ny]) {
					q.push(make_pair(nx, ny)); icebox[nx][ny] = group;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%1d", &icebox[i][j]);
		}
	}
	int group = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!icebox[i][j]) {
				bfs(i, j, ++group);
			}
		}
	}
	cout << group - 1 << '\n';
	return 0;
}
/*
15 14
00000111100000
11111101111110
11011101101110
11011101100000
11011111111111
11011111111100
11000000011111
01111111111111
00000000011111
01111111111000
00011111111000
00000001111000
11111111110011
11100011111111
11100011111111
*/