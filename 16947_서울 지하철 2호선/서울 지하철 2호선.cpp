#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int>a[3000];
int dist[3000];
int check[3000];
int n;
queue<int>q;
// -2 �� ����Ŭ ����, ����Ŭ�� ������ ���� ����
// -1�� ����Ŭ ���� ��ã��
// 0 ~ n-1�� ����Ŭ ����, ����Ŭ�� ���ԵǹǷ� ����Ŭ�� ���� �ε����� ����
int dfs(int x,int px) {
	// �̹� �湮 ������ ���� �ε��� ����
	if (check[x]==1) return x;
	// �ƴϸ� �湮 üũ�ϰ�
	check[x] = 1;
	// ��������Ʈ ��ȸ ����
	for (int nx : a[x]) {
		// �Դ� �� �ǵ��� ���°� ����
		if (nx == px) continue;
		// search -> �湮���� üũ �� �ϴ� ������ ���� ������ ���� ���� ���ϹǷν� 
		// continue ����� �̹� �湮 �ߴٸ� �ٸ� �ĺ��� ã���Ƿ�
		// check�� ���� �ʿ� ����.
		int res = dfs(nx, x);
		// ����Ŭ ����, ����Ŭ�� ������ ���� ����
		if (res == -2) return -2;
		// ����Ŭ ���� ��ȯ
		if (res >= 0) {
			check[x] = 2;
			// ���� ��� ������ ����ε� ���� ��ġ�� ���۳���� => ����Ŭ ��ȸ �� 
			// ���� ��忡 ����� ����Ŭ�� ������ ���� �������� ��󳻱� ���� 
			// ���۳�� ������ ���� -2���� ����
			// res�� ������ ����� ���� ���̰�, �� ���� ���� -2�ƴϸ� ���� ����ε�, -2�� �̹� ������ �ɷ����Ƿ�
			// ���⼭�� �ݵ�� ���۳���̰� �װ��� ���� �����̶��, ���۳���̴�.
			// dfs(����Ŭ�������ʰ� ���۳�忡 �پ��ִ³��,���۳��)�� -2�� �����ϰ� �����.
			if (x == res) return -2;
			// ����Ŭ ��ȸ ���ε� ���۳�� ���� �� ����, ���� ��� ����
			else return res;
		}
	}
	// ��ȯ �߿� ���̻� �� �� ������ -1����
	return -1;
}
void bfs() {
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int nx : a[x]) {
			if (dist[nx] == -1) {
				q.push(nx);
				dist[nx] = dist[x] + 1;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int from, to;
		cin >> from >> to;
		from -= 1; to -= 1;
		a[from].push_back(to);
		a[to].push_back(from);
	}
	dfs(0, -1);
	for (int i = 0; i < n; ++i) {
		if (check[i] == 2) {
			dist[i] = 0;
			q.push(i);
		}
		else {
			dist[i] = -1;
		}
	}
	bfs();
	for (int i = 0; i < n; ++i) {
		cout << dist[i] << ' ';
	}
	cout << '\n';
	return 0;
}