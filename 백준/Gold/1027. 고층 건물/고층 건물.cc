#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <deque>
using namespace std;

int building[51];
int N;
int cnt[51];
int result = 0;

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		building[i] = tmp;
	}
}

void solve() {
	for (int i = 0; i < N; i++) {
		double max = -1000000000;
		for (int j = i + 1; j < N; j++) {
			double gi = (double)(building[i] - building[j]) / (i - j);
			if (gi > max) {
				cnt[i]++;
				cnt[j]++;
				max = gi;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (cnt[i] > result) result = cnt[i];
	}
}

int main() {
	init();
	solve();
	cout << result;
}