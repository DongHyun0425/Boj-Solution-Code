#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int board[100][100];
long long d[100][100];

int N;

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp = 0;
			cin >> temp;
			board[i][j] = temp;
		}
	}
}

int main() {
	cin >> N;
	init();

	d[0][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp = d[i][j];
			int jump = board[i][j];

			if (jump == 0 || temp == 0)continue;

			//->
			if (j + jump < N) d[i][j + jump] += d[i][j];
			//아래
			if (i + jump < N)d[i + jump][j] += d[i][j];
		}
	}

	cout << d[N - 1][N - 1];
}