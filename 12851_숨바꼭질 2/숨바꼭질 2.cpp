#include <iostream>
#include <queue>

#define MaxInput 100001

using namespace std;

int time[MaxInput];
int check[MaxInput];
int n, k;
int cnt;

void bfs(int start) {
	queue<int> q;
	q.push(start);
	time[start] = 0;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		if (now == k) cnt += 1;
		check[now] = true;
		// 파이썬 처럼 되네
		for (int next : {now + 1, now - 1, now * 2}) {
			if (next >= 0 && next < MaxInput) {
				// 경우의 수를 세기 위해 이미 방문 했더라도 시간이 같다면 큐에 넣는다.
				// k를 여러번 갈 수 있게 계속 큐에 넣는다.
				// 사실상 브루트 포스임
				// bfs는 한 번씩 방문인데
				//  time[next] == time[now] + 1 이 조건에 의해 밑의 조건문에 들어갈 때는 이미 time[next]의 값이 구해져 있다.
				// 즉, now에서 한번의 연산에 의해 next를 갈 수있는데 그 값이 최소시간하고 동일할 때 큐에 넣는다.
				if (!check[next] || time[next] == time[now] + 1) {
					q.push(next);
					check[next] = true;
					time[next] = time[now] + 1;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> k;
	bfs(n);
	cout << time[k] << '\n' << cnt << '\n';
	return 0;
}