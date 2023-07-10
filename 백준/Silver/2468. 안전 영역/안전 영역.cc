#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
char map[100][100];
int visited[100][100];
int copymap[100][100];
int n;
int dx[4] = { 1,-1,0,0};
int dy[4] = { 0,0,1,-1};

//dfs
void dfs(int y, int x) {
	int nx, ny;
	for (int i = 0; i < 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < n && visited[ny][nx] == 0 && copymap[ny][nx] < 101) {
			visited[ny][nx] = 1;
			dfs(ny, nx);
		}
	}
}

int main() {
	cin >> n;
	//맵설정하기
	int max = 0;
	int result[100] = {0};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int k = 0;
			cin >> k;
			if (k > max) { max = k; }
			map[i][j] = k;
		}
	}

	for (int i = 0; i < max; i++) {
		int cnt = 0;
		//copymap에 map복사
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
				copymap[a][b] = map[a][b];
			}
		}
		//넘치는 부분 200으로 설정
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if (copymap[y][x] <= i) {
					copymap[y][x] = 200;
				}
			}
		}

		//완전탐색 후 dfs호출
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j] == 0 && copymap[i][j] < 150) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		result[i] = cnt;
		memset(visited, 0, sizeof(visited));
	}

	sort(result, result + 100, greater<int>());
	cout << result[0];
	return 0;
}