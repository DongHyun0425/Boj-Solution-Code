#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
int map[50][50];
int visited[50][50];
int w, h;
int dx[4] = { 1,-1,0,0};
int dy[4] = { 0,0,1,-1};

void dfs(int y, int x) {
	int nx = 0;
	int ny = 0;
	for (int i = 0; i < 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		//가로 세로가 사각형 안에 있어야되고, map에서는 1이고 visited에서는 방문을 아직하지 않아야 된다.
		if (nx>=0&&ny>=0&&nx<w&&ny<h&&map[ny][nx] == 1 && visited[ny][nx] == 0) {
			//조건만족시 방문처리를 해주고 재귀함수로 불러온다.
			visited[ny][nx]=1;
			dfs(ny, nx);
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> w >> h;
		int cnt = 0;
		int b = 0;
		cin >> b;
		for (int k = 0; k < b; k++) {
			int a, b;
			cin >> a >> b;
			map[b][a] = 1;
		}

		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				if (map[y][x] == 1 && visited[y][x] == 0) {
					dfs(y, x);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
		fill(&visited[0][0], &visited[50][50], 0);
		fill(&map[0][0], &map[50][50], 0);
	}
	return 0;
}