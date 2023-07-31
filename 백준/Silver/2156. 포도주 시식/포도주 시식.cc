#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable : 4996)

using namespace std;

vector<int> v;
vector<int> dp;

int max(int a, int b) {
	if (a > b) { return a; }
	else { return b; }
}

void DynamicProgramming(int n) {
	for (int i = 3; i < n + 3; i++) {
		dp.push_back(max(max(dp[i - 3] + v[i - 1] + v[i], dp[i - 2] + v[i]), dp[i - 1]));
	}
}

int main() {
	int n = 0;
	cin >> n;
	for (int i = 0; i < 3; i++) {
		v.push_back(0);
		dp.push_back(0);
	}

	for (int i = 0; i < n; i++) {
		int k = 0;
		cin >> k;
		v.push_back(k);
	}
	DynamicProgramming(n);
	cout << dp.back();
}