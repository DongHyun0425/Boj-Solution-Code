#include <iostream>
#include <vector>
#include <utility>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;
int R, C;
char graph[100][100];
bool visited[100][100];
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int result = 0;
int Time=0;

bool bfs() {
	visited[0][0] = true;
	int cnt = 0;
	queue<pair<int, int>>q;
	q.push({ 0,0 });
	Time++;
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dir[i][0];
			int nc = c + dir[i][1];
			if (nr >= 0 && nr < R && nc >= 0 && nc < C && !visited[nr][nc]) {
				//내가 지금 공기인데, 같은 공기면 queue에 넣기
				if (graph[nr][nc] == '0') {
					q.push({ nr,nc });
				}
				//내가 지금 공기인데, 옆칸이 치즈면, 치즈를 0으로 바꾸고 quque에 안넣기
				else{
					graph[nr][nc] = '0';
					cnt++;
				}
				visited[nr][nc] = true;
			}
		}
	}
	if (cnt == 0) {
		cout << --Time << "\n" << result;
		return true;
	}
	else {
		result = cnt;
		return false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> graph[i][j];
		}
	}
	//치즈가 없을 때까지
	while (true) {
		if (bfs())
			break;
		memset(visited, false, sizeof(visited));
	}

	return 0;
}