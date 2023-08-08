#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n = 0;
	cin >> n;
	vector<long long>dp;
	if (n == 1) { cout << 1; }
	else if(n == 2) { cout << 2; }
	else {
		dp.push_back(1);
		dp.push_back(2);
		for (int i = 2; i < n; i++) {
			dp.push_back((dp[i - 2] + dp[i - 1]) % 15746);
		}
		cout << dp.back();
	}
}