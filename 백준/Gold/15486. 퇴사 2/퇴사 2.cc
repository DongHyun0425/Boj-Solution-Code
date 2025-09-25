#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

long long DP[1500003];
int N = 0;

void init() {
	cin >> N;
}

void solve() {
	for (int i = 1; i <= N; i++) {
		if (DP[i] < DP[i - 1]) {
			DP[i] = DP[i - 1];
		}
		int day = 0;
		int cost = 0;

		cin >> day >> cost;

		if (i + day - 1 <= N) {
			DP[i + day - 1] = max(DP[i + day - 1], DP[i-1] + cost);
		}
	}
	cout << DP[N];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	init();
	solve();
}