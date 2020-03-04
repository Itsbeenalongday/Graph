#include <iostream>
#include <vector>
#include <queue>
// bfs의 과정을 다시 공부하게 된 문제.. ㅠㅠ
using namespace std;

int box[1000][1000];
int dist[1000][1000];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m; 
queue<pair<int, int>>q;

bool range_check(int x, int y) {
	if (x < 0) return false;
	if (x >= n) return false;
	if (y < 0) return false;
	if (y >= m) return false;
	return true;
}

void bfs() {
	while (!q.empty()) {
		int x = q.front().first; int y = q.front().second; q.pop();
		for (int k = 0; k < 4; ++k) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (range_check(nx, ny)) {
				// 덜익은 토마토이고 아직 가지 않은
				if (box[nx][ny] == 0 && dist[nx][ny] == -1) {
					q.push(make_pair(nx, ny));
					dist[nx][ny] = dist[x][y] + 1;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> m >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> box[i][j];
			dist[i][j] = -1;
			if (box[i][j] == 1) {
				// 시작점을 모두 넣고 시작
				// 첫번째 시작점이 끝나면 두번째 시작점 ... 
				q.push(make_pair(i, j));
				dist[i][j] = 0;
			}
		}
	}
	bfs();
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (ans < dist[i][j]) {
				ans = dist[i][j];
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (box[i][j] == 0 && dist[i][j] == -1) {
				ans = -1;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}