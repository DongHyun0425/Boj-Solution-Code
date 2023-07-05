#include <iostream>
#include <queue>
using namespace std;

const int mxN = 8, dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
int n, m, a[mxN][mxN];
int tmp[mxN][mxN];
int ans = 0;
bool vis[mxN][mxN];

void copy(int tmp[mxN][mxN], int a[mxN][mxN]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp[i][j] = a[i][j];
		}
	}
}

void bfs() {
	int after[8][8];
	copy(after, tmp);

	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (after[i][j] == 2) {
				q.push({ i, j });
			}
		}
	}

	while (q.size()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (after[nx][ny] == 0) {
				after[nx][ny] = 2;
				q.push({ nx, ny });
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (after[i][j] == 0) {
				cnt++;
			}
		}
	}
	ans = max(ans, cnt);
}

void wall(int cur) {
	if (cur == 3) {
		bfs();
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp[i][j] == 0) {
				tmp[i][j] = 1;
				wall(cur + 1);
				tmp[i][j] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) {
				//memset(vis, 0, sizeof(vis));
				copy(tmp, a);
				tmp[i][j] = 1;
				wall(1);
				tmp[i][j] = 0;
			}
		}
	}

	cout << ans;
}