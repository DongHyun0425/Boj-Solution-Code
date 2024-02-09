#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m = 0;
int map[301][301] = { 0, };
int temp[301][301] = { 0, };
int visited[301][301] = { 0, };
int cnt = 1;
int year = 0;
int checkmap = 0;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool check() {
	int mapcheck = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] > 1) {
				return false;
			}
			if (map[i][j] != 0) {
				mapcheck++;
			}
			visited[i][j] = 0;
		}
	}
	if (mapcheck == 0) {
		checkmap++;
		return false;
	}
	else {
		cnt = 1;
		return true;
	}
}

void dfs(int i, int j) {
	visited[i][j] = cnt;
	int ice = 0;
	if (i>=0&&j>=0&&i<n&&j<m&&temp[i-1][j] == 0) ice++;
	if (i >= 0 && j >= 0 && i < n && j < m && temp[i+1][j] == 0) ice++;
	if (i >= 0 && j >= 0 && i < n && j < m && temp[i][j-1] == 0) ice++;
	if (i >= 0 && j >= 0 && i < n && j < m && temp[i][j+1] == 0) ice++;
	if (map[i][j] - ice < 0) {
		map[i][j] = 0;
	}
	else {
		map[i][j] -= ice;
	}
	for (int a = 0; a < 4; a++) {
		int nx = i + dx[a];
		int ny = j + dy[a];
		if (nx >= 0 && ny >= 0 && nx < n && ny < m && visited[nx][ny] == 0 && temp[nx][ny] != 0) {
			dfs(nx, ny);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp = 0;
			cin >> tmp;
			map[i][j] = tmp;
			temp[i][j] = tmp;
		}
	}

	while (check()) {
		year++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (temp[i][j] != 0 && visited[i][j] == 0) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		//map을 다시 temp에 복사
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				temp[i][j] = map[i][j];
			}
		}
	}
	if (checkmap > 0) {
		cout << 0;
	}
	else {
		cout << year-1;
	}
}