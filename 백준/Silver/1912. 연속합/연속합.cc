#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
//두번째가 끝자리의 숫자 x1,xx2이런식
vector <int> dp;
vector  <int> v;

void DP(int n) {
	dp.push_back(v[0]);
	for (int i = 1; i < n; i++) {
		dp.push_back(v[i]);
		if (dp[i]<dp[i]+dp[i-1]) {
			dp[i]=dp[i] + dp[i - 1];
		}
	}
	cout << *max_element(dp.begin(),dp.end());
}
int main() {
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		v.push_back(k);
	}
	DP(n);

}