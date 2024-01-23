#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
#include <tuple>
#include <map>
#include <unordered_set> 
using namespace std;

int N, M, result = 0;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
int mymap[8][8] = { 0, };
int tempmap[8][8] = { 0, };
void copy() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			tempmap[i][j] = mymap[i][j];
		}
	}
}

void dfs(int i, int j) {
	for (int x = 0; x < 4; x++) {
		int nx = i + dx[x];
		int ny = j + dy[x];
		if (nx >= 0 && ny >= 0 && nx < N && ny < M && tempmap[nx][ny] == 0) {
			tempmap[nx][ny] = 2;
			dfs(nx, ny);
		}
	}
}

int check() {
	int safe = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tempmap[i][j] == 0) {
				safe++;
			}
		}
	}
	return safe;
}

void spreadVirus() {
	copy();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tempmap[i][j] == 2) {
				dfs(i, j);
			}
		}
	}

	int safe = check();
	if (safe > result) {
		result = safe;
	}

}

void initiate() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			tempmap[i][j] = 0;
		}
	}
}

void make_wall(int cnt) {
	if (cnt == 2) {
		spreadVirus();
		initiate();
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (mymap[i][j] == 0) {
				cnt++;
				mymap[i][j] = 1;
				make_wall(cnt);
				cnt--;
				mymap[i][j] = 0;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int temp = 0;
			cin >> temp;
			mymap[i][j] = temp;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int cnt = 0;
			if (mymap[i][j] == 0) {
				mymap[i][j] = 1;
				make_wall(cnt);
				mymap[i][j] = 0;
			}
		}
	}
	cout << result;
}