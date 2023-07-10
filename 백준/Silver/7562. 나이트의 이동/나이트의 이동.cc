#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int map[300][300] = { 0 };
queue <pair<int, int>> q;
int n = 0;
int dx[8] = { 1,2,1,2,-2,-2,-1,-1 };
int dy[8] = { 2,1,-2,-1,1,-1,2,-2 };


void bfs(int b, int a) {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny == b && nx == a) { 
				cout << map[y][x] + 1 << endl;
				
				while (!q.empty()) {
					q.pop();
				}
				
				break; 
			}
			else if (ny >= 0 && nx >= 0 && ny < n && nx < n && map[ny][nx] == 0) {
				map[ny][nx] = map[y][x] + 1;
				q.push({ ny, nx });
			}
		}
	}
}


int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		int x = 0;
		int y = 0;
		cin >> y;
		cin >> x;
		q.push({ y, x });// 초기위치 일단 q에 push
		
		cin >> y; //목표 위치 받기
		cin >> x;
		
		if (q.front().first == y && q.front().second == x) { cout << "0" << endl; }
		else {
			bfs(y, x);
		}

		//맵초기화 후 다음 케이스 실행
		for (int i = 0; i < 300; i++) {
			for (int j = 0; j < 300; j++) {
				map[i][j] = 0;
			}
		}
	}
	return 0;
}