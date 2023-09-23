#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int main(){
	int N;
	cin >> N;
	int arr[301] = { 0, };
	int dp[301] = { 0, };

	for (int i = 0; i < N; i++) {
		int k = 0;
		cin >> k;
		arr[i] = k;
	}

	dp[0] = arr[0];
	dp[1] = max(arr[0] + arr[1], arr[1]);
	dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);

	for (int i = 3; i < N; i++) {
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1]+arr[i]);
	}
	cout << dp[N - 1];
}