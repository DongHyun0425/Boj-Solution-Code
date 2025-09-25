#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

int H = 0;
int W = 0;

bool map[501][501] = {false,};

void init() {
	cin >> H >> W;

	//3 0 1 4
	for (int i = 0; i < W; i++) {
		int tmp = 0;
		cin >> tmp;

		for (int j = 0; j < tmp; j++) {
			map[j][i] = true;
		}
	}
}

void solve() {
	int Answer = 0;
	for (int i = 0; i < H; i++) {
		bool flag = false;
		int temp = 0;
		for (int j = 0; j < W; j++) {
			//블럭인경우
			if (map[i][j]) {
				//첫빠따인경우
				if (!flag) flag = true;
				else {
					Answer += temp;
					temp = 0;
					flag = true;
				}
			}
			else if(flag) {
				//	빈공강
				temp++;
			}

		}
	}
	cout << Answer;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	init();
	solve();
}