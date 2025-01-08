#include <iostream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
using namespace std;

int N = 0;
int map[17][17];
int Answer = 0;

class Pipe {
public:
	int left_x;
	int left_y;
	int right_x;
	int right_y;
	int shape;

	Pipe(int a, int b, int c, int d, int e) {
		left_x = a;
		left_y = b;
		right_x = c;
		right_y = d;
		shape = e;
	}
};

bool check(int lx,int ly,int rx,int ry,int shape) {
	if (shape == 3) {
		if (lx >= 1 && lx <= N && rx >= 1 && ry <= N && map[lx][ly] != 1 && map[rx][ry] != 1 && map[rx][ry-1]!=1 && map[rx-1][ry]!=1) {
			return true;
		}
		else {
			return false;
		}
	}
	if (lx >= 1 && lx <= N && rx >= 1 && ry <= N && map[lx][ly] != 1 && map[rx][ry] != 1) {
		return true;
	}
	return false;
}

void dfs(Pipe pipe) {
	int lx = pipe.left_x;
	int ly = pipe.left_y;
	int rx = pipe.right_x;
	int ry = pipe.right_y;
	int shape = pipe.shape;

	//어느 한쪽이 N,N에 닿은 경우
	if ((lx == N && ly == N) || (rx == N && ry == N)) {
		Answer++;
		return;
	}

	//가로모양인경우
	if (shape == 1) {
		//오른쪽으로 이동,가로모양
		int n_lx = rx;
		int n_ly = ry;
		int n_rx = rx;
		int n_ry = ry + 1;
		if (check(n_lx, n_ly, n_rx, n_ry,1)) {
			dfs(Pipe(n_lx, n_ly, n_rx, n_ry,1));
		}

		//대각선 이동, 대각선모양
		 n_rx = rx + 1;
		 n_ry = ry + 1;
		if (check(n_lx, n_ly, n_rx, n_ry,3)) {
			dfs(Pipe(n_lx, n_ly, n_rx, n_ry, 3));
		}
	}//세로모양인경우
	else if (shape == 2) {
		//아래로 이동, 아래모양
		int n_lx = rx;
		int n_ly = ry;
		int n_rx = rx+1;
		int n_ry = ry;
		if (check(n_lx, n_ly, n_rx, n_ry,2)) {
			dfs(Pipe(n_lx, n_ly, n_rx, n_ry, 2));
		}

		//대각선 이동, 대각선모양
		n_rx = rx + 1;
		n_ry = ry + 1;
		if (check(n_lx, n_ly, n_rx, n_ry,3)) {
			dfs(Pipe(n_lx, n_ly, n_rx, n_ry, 3));
		}
	}//대각선모양인경우
	else {
		//대각모양 그대로 밀기, 대각선모양
		int n_lx = rx;
		int n_ly = ry;
		int n_rx = rx + 1;
		int n_ry = ry + 1;
		if (check(n_lx, n_ly, n_rx, n_ry,3)) {
			dfs(Pipe(n_lx, n_ly, n_rx, n_ry, 3));
		}

		//가로로이동, 가로모양
		n_rx = rx;
		n_ry = ry + 1;
		if (check(n_lx, n_ly, n_rx, n_ry,1)) {
			dfs(Pipe(n_lx, n_ly, n_rx, n_ry, 1));
		}
		//세로로이동, 세로모양
		n_rx = rx + 1;
		n_ry = ry;
		if (check(n_lx, n_ly, n_rx, n_ry,2)) {
			dfs(Pipe(n_lx, n_ly, n_rx, n_ry, 2));
		}
		
	}
}


int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int temp = 0;
			cin >> temp;
			map[i][j] = temp;
		}
	}

	Pipe pipe = Pipe(1, 1, 1, 2, 1);

	dfs(pipe);
	cout << Answer;
	return 0;
}