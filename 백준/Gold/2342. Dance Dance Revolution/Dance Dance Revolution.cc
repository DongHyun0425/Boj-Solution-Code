#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

int dp[100003][5][5];

void init() {
	for (int i = 0; i < 100003; i++) {
		for (int j = 0; j < 5; j++) {
			for (int x = 0; x < 5; x++) {
				dp[i][j][x] = 5000000;
			}
		}
	}
}

int cost(int current, int next) {
	if (current == 0)return 2;
	if (abs(current - next) == 2) return 4;
	if (current == next)return 1;
	return 3;
}

void solve() {
	int temp = 100;
	int idx = 0;
	dp[idx][0][0] = 0;
	while (temp != 0) {
		cin >> temp;

		for (int r = 0; r < 5; r++) {
			for (int l = 0; l < 5; l++) {
				//왼쪽발이 움직이는경우
				dp[idx + 1][temp][r] = min(dp[idx + 1][temp][r], dp[idx][l][r] + cost(l, temp));

				//오른쪽 발이 움직이는 경우
				dp[idx + 1][l][temp] = min(dp[idx + 1][l][temp], dp[idx][l][r] + cost(r, temp));
			}
		}
		idx++;
	}

	int Answer = 5000000;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (Answer > dp[idx-1][i][j]) Answer = dp[idx-1][i][j];
		}
	}
	cout << Answer;
}

int main() {
	init();
	solve();
}