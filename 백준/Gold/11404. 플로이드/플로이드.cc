#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N = 0;
	int M = 0;
	cin >> N >> M;

	int grap[101][101] = {0, };

	for (int i = 1; i < N+1; i++) {
		for (int j = 1; j < N+1; j++) {
			grap[i][j] = 11000000;
		}
	}

	for (int i = 0; i < M; i++) {
		int x = 0;
		int y = 0;
		int h = 0;
		cin >> x >> y >> h;
		if (grap[x][y] > h) { grap[x][y] = h; }
	}

	for (int i = 0; i < 101; i++) {
		grap[i][i] = 0;
	}

	for (int k = 1; k < N+1; k++) {
		for (int i = 1; i < N+1; i++) {
			for (int j = 1; j < N+1; j++) {
				grap[i][j] = min(grap[i][j], grap[i][k] + grap[k][j]);
			}
		}
	}

	for (int i = 1; i < N+1; i++) {
		for (int j = 1; j < N+1; j++) {
			if (grap[i][j] == 11000000) { cout << "0 "; }
			else { cout << grap[i][j]<<" "; }
		}
		cout << endl;
	}
}