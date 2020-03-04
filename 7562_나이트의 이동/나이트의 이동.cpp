#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int dx[] = { -2,-1,1,2,2,1,-1,-2 };
int dy[] = { 1,2,2,1,-1,-2,-2,-1 };
int l;
int dist[300][300];

queue<pair<int, int>>q;

bool range_check(int x, int y) {
	if (x < 0) return false;
	if (x >= l) return false;
	if (y < 0) return false;
	if (y >= l) return false;
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> l;
		int sx, sy;
		int ex, ey;
		cin >> sx >> sy >> ex >> ey;
		// 초기화
		memset(dist, 0, sizeof(dist));
		q.push(make_pair(sx, sy));
		dist[sx][sy] = 0;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int k = 0; k < 8; ++k) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (range_check(nx, ny)) {
					if (dist[nx][ny] == 0) {
						dist[nx][ny] = dist[x][y] + 1;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
		// 시작 = 도착 예외
		if (sx == ex && sy == ey) {
			dist[ex][ey] = 0;
		}
		cout << dist[ex][ey] << '\n';
	}
	return 0;
}