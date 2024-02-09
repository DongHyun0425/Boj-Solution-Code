#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[31] = { 0, };

int main() {
	int n = 0;
	cin >> n;
	int result = 0;
	dp[0] = 1;
	dp[2] = 3;
	dp[4] = 11;
	if (n % 2 == 1) {
		cout << 0;
	}else if (n == 2) {
		cout << 3;
	}
	else if (n == 4) {
		cout << 11;
	}
	else {
		int cnt = 4;
		while (n != cnt) {
			int temp = 0;
			cnt += 2;
			int tt = cnt;
			temp += dp[cnt - 2] * dp[2];
			tt -= 4;
			while (tt >= 0) {
				temp += dp[tt] * 2;
				tt -= 2;
			}
			dp[cnt] = temp;
		}
		cout << dp[n];
	}
}