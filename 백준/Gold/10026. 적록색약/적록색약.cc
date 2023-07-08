#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
char map[100][100];
int visited[100][100];
int n;
int dx[4] = { 1,-1,0,0};
int dy[4] = { 0,0,1,-1};

//정상 일경우dfs
void dfs1(int i, int j,char c,int cnt) {
	int nx=0;
	int ny=0;
	for (int k = 0; k < 4; k++) {
		nx = j + dx[k];
		ny = i + dy[k];
		if (nx >= 0 && ny >= 0 && nx < n && ny < n && visited[ny][nx] == 0 && map[ny][nx]==c) {
			visited[ny][nx] = cnt;
			dfs1(ny, nx, c, cnt);
		}
	}
}

//비정상일경우 dfs
void dfs2(int i, int j, char c, int cnt) {
	int nx = 0;
	int ny = 0;
	if (c == 'B') {
		for (int k = 0; k < 4; k++) {
			nx = j + dx[k];
			ny = i + dy[k];
			if (nx >= 0 && ny >= 0 && nx < n && ny < n && visited[ny][nx] == 0 && map[ny][nx] == c) {
				visited[ny][nx] = cnt;
				dfs2(ny, nx, c, cnt);
			}
		}
	}
	else {
		for (int k = 0; k < 4; k++) {
			nx = j + dx[k];
			ny = i + dy[k];
			if (nx >= 0 && ny >= 0 && nx < n && ny < n && visited[ny][nx] == 0 && map[ny][nx] !='B') {
				visited[ny][nx] = cnt;
				dfs2(ny, nx, c, cnt);
				cnt++;
			}
		}
	}
}

int main() {
	cin >> n;
	int cnt = 1;
	//1: 맵설정
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			map[i][j] = s[j];
		}
	}
	
	//2번: 모든 원소로 부터 완전탐색(다만, 방문경험이 없는 원소만 차례대로)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0) {
				dfs1(i, j, map[i][j], cnt);
				cnt++;
			}
		}
	}
	cout << cnt-1 << " ";
	cnt = 1;
	//visited 초기화]
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			visited[i][j] = 0;
		}
	}
	
	//4번: 적녹으로 다시:
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0) {
				dfs2(i, j, map[i][j], cnt);
				cnt++;
			}
		}
	}
	cout << cnt - 1;
	return 0;
}