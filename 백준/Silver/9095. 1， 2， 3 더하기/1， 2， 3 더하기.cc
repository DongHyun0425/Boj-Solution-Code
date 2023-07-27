#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable : 4996)

using namespace std;

int dp[12] = { 0 };
void make() {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < 12; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
}
int main() {
	int T;
	cin >> T;
	make();
	for (int i = 0; i < T; i++) {
		int a = 0;
		cin >> a;
		cout << dp[a]<<endl;
	}
}