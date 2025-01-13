#include <stdio.h>
#include<iostream>
#include <cmath>
#include<vector>
#include<queue>
#include <cstring>
using namespace std;

int map[52][52];
bool visited[52][52];
int N, L, R;
bool flag = true;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void bfs(int i, int j) {
	queue<pair<int, int>> q;
	int cnt = 0;
	int p = 0;
	vector<pair<int, int>>v;
	q.push({ i, j });
	visited[i][j] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		v.push_back({ x,y });
		q.pop();
		cnt++;
		p += map[x][y];
		for (int a = 0; a < 4; a++) {
			int nx = x + dx[a];
			int ny = y + dy[a];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny] && abs(map[x][y] - map[nx][ny]) >= L && abs(map[x][y] - map[nx][ny]) <= R) {
				flag = false;
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}

	if (cnt > 1) {
		int population = p / cnt;
		for (int i = 0; i < v.size(); i++) {
			int x = v[i].first;
			int y = v[i].second;

			map[x][y] = population;
		}
	}
}

int main() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp = 0;
			cin >> tmp;

			map[i][j] = tmp;
		}
	}

	int ans = 0;
	while (1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) bfs(i, j);
			}
		}
		if (flag) break;
		ans++;
		flag = true;
		for (int i = 0; i < N; i++) {
			memset(visited[i], false, sizeof(bool) * N); //모든 값 0으로 초기화}
		}
	}
	cout << ans;
}