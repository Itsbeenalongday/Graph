#include <iostream>
#include <deque>
#define max 1000001
using namespace std;

bool check[max];
int time[max];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	check[n] = true;
	time[n] = 0;
	deque<int> d;
	d.push_back(n);
	while (!d.empty()) {
		int now = d.front();
		d.pop_front();
		if (now * 2 < max) {
			if (!check[now * 2]) {
				d.push_front(now * 2);
				check[now * 2] = true;
				time[now * 2] = time[now];
			}
		}
		if (now - 1 >= 0) {
			if (!check[now - 1]) {
				d.push_back(now - 1);
				check[now - 1] = true;
				time[now - 1] = time[now] + 1;
			}
		}
		if (now + 1 < max) {
			if (!check[now + 1]) {
				d.push_back(now + 1);
				check[now + 1] = true;
				time[now + 1] = time[now] + 1;
			}
		}
	}
	cout << time[m] << '\n';
	return 0;
}