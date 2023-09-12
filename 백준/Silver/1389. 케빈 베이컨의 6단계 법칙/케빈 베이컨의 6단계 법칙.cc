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
			grap[i][j] = 100;
		}
	}

	for (int i = 0; i < M; i++) {
		int k = 0;
		int j = 0;
		cin >> k >> j;
		grap[k][j] = 1;
		grap[j][k] = 1;
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

	vector<int>v;
	for (int i = 1; i < N+1; i++) {
		int h = 0;
		for (int j = 1; j < N+1; j++) {
			h += grap[i][j];
		}
		v.push_back(h);
	}

	cout<< min_element(v.begin(), v.end()) - v.begin()+1;
}