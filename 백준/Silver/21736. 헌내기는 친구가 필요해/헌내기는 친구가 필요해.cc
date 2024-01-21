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

char mymap[600][600];
bool visited[600][600];
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };
int N, M = 0;
int cnt = 0;

void Dfs(int x,int y) {
	if (mymap[x][y] == 'P') {
		cnt++;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x+dx[i];
		int ny = y+dy[i];
		if (nx >= 0 && ny >= 0 && nx < N && ny < M && !visited[nx][ny] && mymap[nx][ny]!='X') {
			visited[nx][ny] = true;
			Dfs(nx, ny);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	int x = 0;
	int y = 0;
	for (int i = 0; i < 600; i++) {
		for (int j = 0; j < 600; j++) {
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char temp;
			cin >> temp;
			if (temp == 'I') {
				x = i, y = j;
			}
			mymap[i][j] = temp;
		}
	}

	Dfs(x, y);
	if (cnt > 0) {
		cout << cnt;
	}
	else {
		cout << "TT";
	}
}