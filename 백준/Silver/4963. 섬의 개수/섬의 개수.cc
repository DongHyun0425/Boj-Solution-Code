#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
int map[50][50];
int visited[50][50];

int dx[8] = { 1,1,0,-1,-1,-1,0,1 }, dy[8] = { 0,1,1,1,0,-1,-1,-1 };

void dfs(int w, int h, int i, int j) {
	for (int a = 0; a < 8; a++) {
		int ny = i + dx[a];
		int nx = j + dy[a];
		if (nx >= 0 && ny >= 0 && nx < w && ny < h && map[ny][nx]==1 && visited[ny][nx]==0) {
			visited[ny][nx] = 1;
			dfs(w, h, ny, nx);
		}
	}
}

int main() {
	while (1) {
		int cnt = 0;
		int w, h;
		cin >> w >> h;
		if (!w && !h)break;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				int k;
				cin >> k;
				map[i][j] = k;
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (visited[i][j] == 0 && map[i][j] == 1) {
					visited[i][j] = 1;
					dfs(w, h, i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}