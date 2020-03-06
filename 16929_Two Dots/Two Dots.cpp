#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
char board[55][55];
bool check[55][55];
int n, m;

bool range_check(int x, int y) {
	if (x < 0) return false;
	if (x >= n) return false;
	if (y < 0) return false;
	if (y >= m) return false;
	return true;
}
bool dfs(int x, int y, int px, int py, char color) {
	if (check[x][y]) return true;
	check[x][y] = true;
	for (int k = 0; k < 4; ++k) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (range_check(nx, ny)) {
			if (!(px == nx && py == ny) && board[nx][ny] == color) {
				if(dfs(nx,ny,x,y,color)) return true;
			}
		}
	}
	return false;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s",board[i]);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (check[i][j]) continue;
			bool cycle = dfs(i, j, -1, -1, board[i][j]);
			if (cycle) {
				printf("Yes\n");
				return 0;
			}
		}
	}
	printf("No\n");
	return 0;
}