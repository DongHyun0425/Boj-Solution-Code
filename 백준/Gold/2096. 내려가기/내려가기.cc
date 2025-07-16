#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
using namespace std;

int N;

int map[100001][3];
int DPS[3];
int DPL[3];

void init() {
	for (int i = 0; i < N; i++) {
		int a=0;
		int b = 0;
		int c=0;
		cin >> a >> b >> c;
		map[i][0] = a;
		map[i][1] = b;
		map[i][2] = c;

		if (i == 0) {
			DPS[0] = a;
			DPS[1] = b;
			DPS[2] = c;
			DPL[0] = a;
			DPL[1] = b;
			DPL[2] = c;
		}
	}
}

void solve() {
	for (int i = 0; i < N - 1; i++) {
		int tmpmax[3];
		int tmpmin[3];

		//왼쪽비교
		int Max = max(DPL[0] + map[i + 1][0], DPL[1] + map[i + 1][0]);
		int Min = min(DPS[0] + map[i + 1][0], DPS[1] + map[i + 1][0]);

		tmpmax[0] = Max;
		tmpmin[0] = Min;

		//오른쪽비교
		int Max1 = max(DPL[1] + map[i + 1][2], DPL[2] + map[i + 1][2]);
		int Min1 = min(DPS[1] + map[i + 1][2], DPS[2] + map[i + 1][2]);

		tmpmax[2] = Max1;
		tmpmin[2] = Min1;


		//가운데 비교
		int Max2 = max(DPL[0] + map[i + 1][1], max(DPL[1] + map[i + 1][1], DPL[2] + map[i + 1][1]));
		int Min2 = min(DPS[0] + map[i + 1][1], min(DPS[1] + map[i + 1][1], DPS[2] + map[i + 1][1]));

		tmpmax[1] = Max2;
		tmpmin[1] = Min2;

		for (int j = 0; j < 3; j++) {
			DPL[j] = tmpmax[j];
			DPS[j] = tmpmin[j];
		}
	}


	cout << max(DPL[0], max(DPL[1], DPL[2])) << " " << min(DPS[0], min(DPS[1], DPS[2]));
}

int main() {
	cin >> N;
	init();
	solve();
}