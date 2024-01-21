#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
#include <tuple>
#include <map>
#include <string>
#include <vector>

using namespace std;
int maap[501][501], visit[501][501];
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };
int N, M, ans = 0;

void dfs(int i, int j, int cnt, int current) {
	if (cnt == 4) {
		if (ans < current) {
			ans = current;
		}
		return;
	}

	for (int k = 0; k < 4; k++) {
		int nx = i + dx[k];
		int ny = j + dy[k];
		if (nx >= 0 && nx < N && ny>=0 && ny < M && visit[nx][ny] == 0) {
			visit[nx][ny] = 1;
			dfs(nx, ny, cnt + 1, current + maap[nx][ny]);
			visit[nx][ny] = 0;
		}
	}

	if (i - 1 >= 0 && j - 1 >= 0 && i + 1 < N) { //ㅓ
		ans = max(ans, (maap[i - 1][j] + maap[i][j - 1] + maap[i][j] + maap[i + 1][j]));
	}
	if (i - 1 >= 0 && j + 1 < M && i + 1 < N) { //ㅏ
		ans = max(ans, (maap[i - 1][j] + maap[i][j + 1] + maap[i][j] + maap[i + 1][j]));
	}
	if (j - 1 >= 0 && j + 1 < M && i + 1 < N) { //ㅗ
		ans = max(ans, (maap[i][j] + maap[i + 1][j] + maap[i + 1][j - 1] + maap[i + 1][j + 1]));
	}
	if (j - 1 >= 0 && j + 1 < M && i + 1 < N) { //ㅜ
		ans = max(ans, (maap[i][j - 1] + maap[i][j] + maap[i][j + 1] + maap[i + 1][j]));
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 501; i++) {
		for (int j = 0; j < 501; j++) {
			visit[i][j] = 0;
		}
	}

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int temp = 0;
			cin >> temp;
			maap[i][j] = temp;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = 1;
			dfs(i, j, 1, maap[i][j]);
			visit[i][j] = 0;
		}
	}
	cout << ans;
}