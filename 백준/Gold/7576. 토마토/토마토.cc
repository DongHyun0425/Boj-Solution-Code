#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int map[1000][1000];
queue<pair<int, int>>q;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int result = 0;

void bfs(int m, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {
				q.push({ i,j });
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < m && ny < n && map[ny][nx]==0) {
				q.push({ ny, nx });
				map[ny][nx] = map[y][x] + 1;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) { cout << "-1"; return; 
			}
			if (map[i][j] > result) { result = map[i][j]; }
		}
	}
	cout << result-1;
}

int main() {
	int m, n;
	cin >> m >> n;
	int check = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			if (x == 0) { check++; }
			map[i][j] = x;
		}
	}
	if (check > 0) {
		bfs(m, n);
	}
	else { cout << "0"; }
}