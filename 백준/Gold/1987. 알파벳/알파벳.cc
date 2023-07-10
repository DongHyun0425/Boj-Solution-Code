#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int w = 0;
int h = 0;
char map[20][20] = { 0 };
int alpha[26] = { 0 };
int dx[4] = { 1,-1,0,0, };
int dy[4] = { 0,0,1,-1 };
int result = 0;

void dfs(int x, int y, int cnt) {
	if (result < cnt) { result = cnt; }
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < w && ny < h && alpha[map[ny][nx]-65] == 0) {
			alpha[map[ny][nx] - 65] = 1;
			dfs(nx, ny, cnt+1);
			alpha[map[ny][nx] - 65] = 0;
		}
	}
}

int main() {
	cin >> h >> w;
	//맵받기
	for (int y = 0; y < h; y++) {
		string s;
		cin >> s;
		for (int x = 0; x < w; x++) {
			map[y][x]=s[x];
		}
	}
	//시작점은 방문으로 처리후 넘겨주기
	alpha[map[0][0] - 65] = 1;
	dfs(0, 0, 1);
	cout << result;
	return 0;
}