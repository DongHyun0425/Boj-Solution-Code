#include <stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int map[21][21] = { 0, };
int dice[6] = { 0,0,0,0,0,0 };
int x, y = 0;
int n = 0;
int N, M = 0;
void movesouth() {
	if (x + 1 >= 0 && y >= 0 && x + 1 < N && y < M && map[x + 1][y] != 0) {
		int temp0 = dice[0];
		int temp1 = dice[1];
		int temp3 = dice[3];
		dice[0] = temp1;
		dice[1] = map[x + 1][y];
		dice[2] = temp3;
		dice[3] = temp0;
		map[x + 1][y] = 0;
		x = x + 1;
		y = y;

		cout << dice[3] << "\n";
	}
	else if (x + 1 >= 0 && y >= 0 && x + 1 < N && y < M && map[x + 1][y] == 0) {
		int temp0 = dice[0];
		int temp1 = dice[1];
		int temp2 = dice[2];
		int temp3 = dice[3];
		dice[0] = temp1;
		dice[1] = temp2;
		dice[2] = temp3;
		dice[3] = temp0;
		map[x + 1][y] = dice[1];
		x = x + 1;
		y = y;

		cout << dice[3] << "\n";
	}
}

void movenorth() {
	if (x - 1 >= 0 && y >= 0 && x - 1 < N && y < M && map[x - 1][y] != 0) {
		int temp3 = dice[3];
		int temp1 = dice[1];
		int temp2 = dice[2];
		dice[0] = temp3;
		dice[1] = map[x - 1][y];
		dice[2] = temp1;
		dice[3] = temp2;
		map[x - 1][y] = 0;
		x = x - 1;
		y = y;

		cout << dice[3] << "\n";
	}
	else if (x - 1 >= 0 && y >= 0 && x - 1 < N && y < M && map[x - 1][y] == 0) {
		int temp3 = dice[3];
		int temp1 = dice[1];
		int temp2 = dice[2];
		int temp0 = dice[0];
		dice[0] = temp3;
		dice[1] = temp0;
		dice[2] = temp1;
		dice[3] = temp2;
		map[x - 1][y] = dice[1];
		x = x - 1;
		y = y;

		cout << dice[3] << "\n";
	}
}

void moveeast() {
	if (x >= 0 && y + 1 >= 0 && x < N && y + 1 < M && map[x][y + 1] != 0) {
		int temp4 = dice[4];
		int temp1 = dice[1];
		int temp3 = dice[3];

		dice[1] = map[x][y + 1];
		dice[3] = temp4;
		dice[4] = temp1;
		dice[5] = temp3;
		map[x][y + 1] = 0;
		x = x;
		y = y + 1;

		cout << dice[3] << "\n";
	}
	else if (x >= 0 && y + 1 >= 0 && x < N && y + 1 < M && map[x][y + 1] == 0) {
		int temp4 = dice[4];
		int temp1 = dice[1];
		int temp3 = dice[3];
		int temp5 = dice[5];
		dice[1] = temp5;
		dice[3] = temp4;
		dice[4] = temp1;
		dice[5] = temp3;
		map[x][y + 1] = dice[1];
		x = x;
		y = y + 1;

		cout << dice[3] << "\n";
	}
}

void movewest() {
	if (x >= 0 && y - 1 >= 0 && x < N && y - 1 < M && map[x][y - 1] != 0) {
		int temp5 = dice[5];
		int temp3 = dice[3];
		int temp1 = dice[1];

		dice[1] = map[x][y - 1];
		dice[3] = temp5;
		dice[4] = temp3;
		dice[5] = temp1;
		map[x][y - 1] = 0;
		x = x;
		y = y - 1;

		cout << dice[3] << "\n";
	}
	else if (x >= 0 && y - 1 >= 0 && x < N && y - 1 < M && map[x][y - 1] == 0) {
		int temp5 = dice[5];
		int temp3 = dice[3];
		int temp1 = dice[1];
		int temp4 = dice[4];
		dice[1] = temp4;
		dice[3] = temp5;
		dice[4] = temp3;
		dice[5] = temp1;
		map[x][y - 1] = dice[1];
		x = x;
		y = y - 1;

		cout << dice[3] << "\n";
	}
}

int main() {
	cin >> N >> M >> x >> y >> n;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int temp = 0;
			cin >> temp;
			map[i][j] = temp;
		}
	}
	for (int i = 0; i < n; i++) {
		int role = 0;
		cin >> role;
		if (role == 4) {
			movesouth();
		}
		else if (role == 3) { 
			movenorth();
		
		}
		else if (role == 1) { 
			moveeast(); 
		}
		else {
			movewest();
		}
	}
}