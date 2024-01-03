#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

int top[500001];
int bottom[500001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, H = 0;
	cin >> N >> H;
	for (int i = 0; i < N; i++) {
		int temp = 0;
		cin >> temp;
		if (i % 2 == 0) {
			bottom[temp]++;
		}
		else {
			top[H - temp + 1]++;
		}
	}

	for (int i = 500000; i > 0; i--) {
		bottom[i - 1] += bottom[i];
	}
	for (int i = 0; i < 500001; i++) {
		top[i+1] += top[i];
	}

	for (int i = 0; i < 500001; i++) {
		bottom[i] += top[i];
	}

	int min = 100000;
	int cnt = 0;
	for (int i = 1; i <= H; i++) {
		if (min > bottom[i]) {
			min = bottom[i];
			cnt = 0;
		}
		if (min == bottom[i]) {
			cnt++;
		}
	}
	cout << min <<"\n";
	cout << cnt;
}