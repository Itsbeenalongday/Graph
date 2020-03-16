#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int time[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	memset(time, -1, sizeof(time));
	queue < pair<int, int>> q;
	q.push(make_pair(1, 0));
	time[1][0] = 0;
	while (!q.empty()) {
		int s, c;
		// q.front()에서 나온 pair의 first와 second가 s와 c에 각각 대응돼 따로 저장시키기 위해 tie()함수 사용
		tie(s, c) = q.front();
		q.pop();
		if (time[s][s] == -1) {
			// 현재 화면의 이모티콘을 클립보드에 저장
			time[s][s] = time[s][c] + 1;
			q.push(make_pair(s, s));
		}
		if (s + c <= n && time[s + c][c] == -1) {
			// 현재화면 + 클립보드 붙여넣기
			time[s + c][c] = time[s][c] + 1;
			q.push(make_pair(s + c, c));
		}
		if (s - 1 >= 0 && time[s - 1][c] == -1) {
			// 현재화면에서 이모티콘 중 하나 삭제
			time[s - 1][c] = time[s][c] + 1;
			q.push(make_pair(s-1, c));
		}
	}
	int ans = -1;
	for (int i = 0; i <= n; ++i) {
		if (time[n][i] != -1) {
			if (ans == -1 || ans > time[n][i]) {
				ans = time[n][i];
			}
		}
	}
	cout << ans << '\n';
	return 0;
}