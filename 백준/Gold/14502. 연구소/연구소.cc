#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m = 0;
int map[8][8];
int tempmap[8][8];
int result=0;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

void copy(int tmp[8][8], int a[8][8]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp[i][j] = a[i][j];
		}
	}
}

void SpreadVirus() {
	//1. 일단 2인거 찾고 push하기 2. 2상하좌우 확인하고 0이면 2 바꾸고 push (while문으로 q 0일때까지) 3. 이거 다하면 count하고 max값이랑 비교해서 크면 집어넣기
	int spreadmap[8][8];
	queue < pair<int, int>> q;
	copy(spreadmap, tempmap);
	//1번
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (spreadmap[i][j] == 2) {
				q.push({ i, j });
			}
		}
	}
	//2번
	while (q.size()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<0 || nx>=n || ny<0 || ny>=m) { continue; }
			if (spreadmap[nx][ny] == 0) {
				spreadmap[nx][ny] = 2;
				q.push({ nx, ny });
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (spreadmap[i][j] == 0) {
				cnt++;
			}
		}
	}

	result = max(result, cnt);
}

void wall(int cnt) {
	if (cnt == 3) {
		SpreadVirus();
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tempmap[i][j] == 0) {
				tempmap[i][j] = 1;
				wall(cnt+1);
				tempmap[i][j] = 0;//SpreadVirsu에서 bfs랑 count까지 전부다하고 나머지 0으로 바꿔줘야함
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int t = 0;
			cin >> t;
			map[i][j] = t;
		}
	}

	//3개 무작위 골라서 벽세우기 함수 만약 하나 벽세우면 wall함수를 이용해서 나머지 2개 벽 다시 세워주기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				copy(tempmap,map);
				tempmap[i][j] = 1;
				wall(1);
				tempmap[i][j] = 0; //맨처음 1넣어준거 0으로 바꿔준느거임 wall함수에서 나머지 2개 1박아둔거 안에서 0으로 다시 되돌려줘야함
			}
		}
	}
	cout << result;
}