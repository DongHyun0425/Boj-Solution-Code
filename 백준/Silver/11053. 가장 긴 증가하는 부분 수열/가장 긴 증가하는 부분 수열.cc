#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable : 4996)

using namespace std;

vector<int> v;
vector<int> dp;

void Dp(int n) {
	for (int i = 1; i < n; i++) {
		if (v[i] > dp.back()) {
			dp.push_back(v[i]);
		}
		else {
			int x = lower_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
			dp[x] = v[i];
		}
	}
	cout << dp.size();
}

int main() {
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		v.push_back(k);
	}
	dp.push_back(v.front());
	Dp(n);
}