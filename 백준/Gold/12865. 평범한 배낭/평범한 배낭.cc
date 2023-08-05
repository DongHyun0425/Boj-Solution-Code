#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
int dp[101][100001];
int w[101];
int v[101];

int main() {
	cin >> N>>K;
	for (int i = 1; i <= N; i++) {
		cin >> w[i] >> v[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			//넣을수 있으면
			if (j - w[i] >= 0) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			}//넣을수 없다면
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[N][K];
}