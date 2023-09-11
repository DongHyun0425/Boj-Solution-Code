#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	int grap[101][101] = { 0 };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int k = 0;
			cin >> k;
			grap[i][j] = k;
		}
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (grap[i][k] == 1 && grap[k][j] == 1) {
					grap[i][j] = 1;
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << grap[i][j]<<" ";
		}
		cout << endl;
	}

}