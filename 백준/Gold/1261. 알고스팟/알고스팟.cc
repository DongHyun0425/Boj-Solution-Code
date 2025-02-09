#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int N;
int M;
int Answer=1000000;
int map[101][101];
bool visited[101][101];
int DP[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void BT(int x, int y, int cnt) {
	DP[x][y] = cnt;
	if (x == M - 1 && y == N - 1 && Answer > cnt) {
		Answer = cnt;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		//map범위 안벗어나고
		if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[nx][ny]) {
			//벽인경우
			if (map[nx][ny] == 1 && cnt + 1 < DP[nx][ny]) {
				visited[nx][ny] = true;
				BT(nx, ny, cnt + 1);
				visited[nx][ny] = false;
			}
			//벽이 아닌경우
			else if (map[nx][ny] == 0 &&cnt<DP[nx][ny]){
				visited[nx][ny] = true;
				BT(nx, ny, cnt);
				visited[nx][ny] = false;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	string str;
	for (int i = 0; i < M; i++) {
		cin >> str;
		for (int j = 0; j < N; j++) {
			map[i][j] = str[j] - '0';
		}
	}
	visited[0][0] = true;
	DP[0][0] = 0;
	for (int i = 0; i < 101; i++) {
		memset(DP[i], 1000000, sizeof(int) * 101); //모든 값 0으로 초기화}
	}
	BT(0,0,0);
	cout << Answer;
}