#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

int Answer = 0;

char board[12][6] = {' ',};
bool visited[12][6] = { false, };
bool flag = false;
bool semiflag = false;
bool total = false;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<pair<int, int>> v;

void init() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> board[i][j];
		}
	}
}

void dfs(int i, int j, char c) {
	visited[i][j] = true;
	v.push_back({ i,j });
	if (v.size() >= 4) {
		flag = true;
		total = true;
	}
	for (int a = 0; a < 4; a++) {
		int nx = i + dx[a];
		int ny = j + dy[a];

		if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
		if (!visited[nx][ny] && board[nx][ny] == c) {
			dfs(nx, ny, c);
		}
	}
}

void check() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			v.clear();
			flag = false;
			if (!visited[i][j] && board[i][j] != '.') dfs(i, j, board[i][j]);

			if (flag) {
				for (int i = 0; i < v.size(); i++) {
					board[v[i].first][v[i].second] = '.';
				}
			}
		}
	}
}

void drop() {
	for (int c = 0; c < 6; c++) {
		int write = 11;//빈공간이랑 바뀔자리
		for (int r = 11; r >= 0; r--) {
			if (board[r][c] != '.') {
				board[write][c] = board[r][c];//.이랑 바꿔줘야함
				if (write != r) board[r][c] = '.';//이거 뭐라 설명해야하지 맨 처음에 B가있으면 '.'로바꾸면안되니까
				write--;
			}
		}
	}
}

void solve() {
	while(1){
		total = false;
		check();//board 변경
		drop();//떨어뜨리기
		if (!total) break;
		Answer++;
	}
	cout << Answer;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	init();
	solve();
}