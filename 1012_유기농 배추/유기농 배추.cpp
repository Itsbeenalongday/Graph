#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int map[50][50];
int g[50][50];
int n, m, p;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

bool range_check(int x, int y) {
	if (x < 0) return false;
	else if (x >= n) return false;
	else if (y < 0) return false;
	else if (y >= m) return false;
	return true;
}
void bfs(int x, int y, int group) {
	queue<pair<int, int>>q; q.push(make_pair(x, y)); g[x][y] = group;
	while (!q.empty()) {
		x = q.front().first; y = q.front().second; q.pop();
		for (int k = 0; k < 4; ++k) {
			int nx = x + dx[k]; int ny = y + dy[k];
			if (range_check(nx, ny)) {
				if (map[nx][ny] == 1 && g[nx][ny] == 0) {
					q.push(make_pair(nx, ny)); g[nx][ny] = group;
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> m >> n >> p;
		// 초기화 필요
		memset(map, 0, sizeof(map));
		memset(g, 0, sizeof(g));
		int cnt = 0;
		// map 렌더링
		for (int i = 0; i < p; ++i) {
			int x, y;
			cin >> y >> x;
			map[x][y] = 1;
		}
		// bfs로 그룹 번호 매기기
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (map[i][j] == 1 && g[i][j] == 0) {
					bfs(i, j, ++cnt);
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}