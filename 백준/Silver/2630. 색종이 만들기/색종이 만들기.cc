#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int map[128][128];
int blue;
int white;

void find(int start, int end, int size) {
	int g = map[start][end];
	for (int i = start; i < start + size; i++) {
		for (int j = end; j < end + size; j++) {
			if (map[i][j] != g) {
				find(start, end, size / 2);
				find(start, end + size / 2, size / 2);
				find(start + size / 2, end, size / 2);
				find(start + size / 2, end + size / 2, size / 2);
				return;
			}
		}
	}
	if (g == 0) {
		white++;
	}
	else { blue++; }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp = 0;
			cin >> temp;
			map[i][j] = temp;
		}
	}

	find(0, 0, N);

	cout << white << endl;
	cout << blue << endl;
}