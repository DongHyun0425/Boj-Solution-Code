#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

int map[101][101];
bool visited[101][101] = {false,};
int change_map[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<pair<int, int>> v;

int N = 0;
int M = 0;
int Answer = 0;
bool flag = true;

void init() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

}

bool check() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j]) return false;
		}
	}
	return true;
}

void dfs(int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
			if (!visited[nx][ny] && !map[nx][ny]) {
				dfs(nx, ny);
			}
			if (flag) {
				map[x][y] = 1;
				v.push_back({ x,y });
			}
		}
		else {
			flag = false;
		}
	}
}

void melt() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			change_map[i][j] = map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j]) {
				int cnt = 0;
				for (int a = 0; a < 4; a++) {
					int nx = i + dx[a];
					int ny = j + dy[a];
					if (nx < 0 || nx >= N || ny < 0 || ny >= M)continue;
					if (!map[nx][ny])cnt++;
				}
				if (cnt >= 2) change_map[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			map[i][j] = change_map[i][j];
		}
	}
}

void solve() {
	while (!check()) {
		Answer++;

		//초기화
		v.clear();
		flag = true;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				visited[i][j] = false;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				flag = true;
				//빈공간인데 방문을안했다.
				if (map[i][j] == 0 && !visited[i][j]) {
					dfs(i, j);
				}
			}
		}

		//치즈의 양옆확인하고 녹이기
		melt();

		//아까 메꾼 치즈 빡구
		for (int i = 0; i < v.size(); i++) {
			map[v[i].first][v[i].second] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	init();
	solve();
	cout << Answer;
}