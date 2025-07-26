#include <string>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//1. init()으로 맵받기
//2. for문으로 R만큼 dfs호출
//3. dfs에서 현재 좌표 방문처리후, 대각 오 대각 확인 
// 만약 진출가능하면 next좌표 넣어주고, 다시 재귀
// 만약 C-1에 도착하면 Answer++해주고 return
// 만약 for문을 전부 돌았는데도 갈곳이 없다 그러면 해당 경로는 안되는것임
// visited취소

int R = 0;
int C = 0;
char map[10001][501];
bool visited[10001][501] = {false,};
int dx[3] = { -1,0,1 };
int dy[3] = { 1,1,1 };
int Answer = 0;

void init() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char tmp=' ';
			cin >> tmp;
			map[i][j]=tmp;
		}
	}
}

bool check(int x, int y) {
	if (x >= 0 && y >= 0 && x < R && y < C && !visited[x][y] && map[x][y] != 'x') {
		return true;
	}
	return false;
}

bool dfs(int x,int y) {
	//현재 좌표 방문처리
	visited[x][y] = true;

	//C-1에 도착한경우 
	if (y == C - 1) {
		Answer++;
		return true;
	}

	for (int i = 0; i < 3; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		//방문가능여부 확인
		if (check(nx, ny)) {
			if (dfs(nx, ny)) {
				return true;
			}
		}
	}
	return false;
}

void solve() {
	//2번
	for (int i = 0; i < R; i++) {
		dfs(i, 0);
	}
}

int main() {
	//1. init()으로 맵받기
	init();
	solve();
	cout << Answer;
}