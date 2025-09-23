#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

void solve() {
	int T = 0;
	cin >> T;
	while (T > 0) {
		T--;
		int dp[501][501] = {0,};
		int sum[501] = {0,};

		int K = 0;
		cin >> K;
		for (int i = 1; i <= K; i++) {
			int temp = 0;
			cin >> temp;
			sum[i] = sum[i - 1] + temp;
		}

		for (int length = 1; length < K; length++) {
			for (int x = 1; x <= K - length; x++) {
				int y = x + length;
				//뒤에 dp에서 min으로 판단해야하니까
				dp[x][y] = 1000000000;
				for (int mid = x; mid < y; mid++) {
					dp[x][y] = min(dp[x][y], dp[x][mid] + dp[mid+1][y] + sum[y] - sum[x-1]);
				}
			}
		}
		cout << dp[1][K] << "\n";
	}	
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}