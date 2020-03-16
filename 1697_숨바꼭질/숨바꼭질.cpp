#include <iostream>
#include <queue>

#define MaxInput 100001

using namespace std;

int time[MaxInput];
int check[MaxInput];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, k;
	cin >> n >> k;
	queue<int> q;
	q.push(n);
	time[n] = 0;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		check[now] = true;
		int next1 = now - 1;
		int next2 = now + 1;
		int next3 = now * 2;
		if (next1 >= 0) {
			if (!check[next1]) {
				q.push(next1);
				check[next1] = true;
				time[next1] = time[now] + 1;
			}
		}
		if (next2 < MaxInput) {
			if (!check[next2]) {
				q.push(next2);
				check[next2] = true;
				time[next2] = time[now] + 1;
			}
		}
		if (next3 < MaxInput) {
			if (!check[next3]) {
				q.push(next3);
				check[next3] = true;
				time[next3] = time[now] + 1;
			}
		}
	}
	cout << time[k] << '\n';
	return 0;
}