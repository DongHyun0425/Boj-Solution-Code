#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable : 4996)

using namespace std;
vector <int>v;
vector <int>dp;

void bfs(int a) {
	int first = 0;
	int last = dp.size() - 1;
	while (first <= last) {
		int mid = (first + last) / 2;
		if (a > dp[mid]) {
			first = mid + 1;
		}
		else {
			last = mid - 1;
		}
	}
	dp[first] = a;
}

int main() {
	int N = 0;
	cin >> N;

	int k = 0;
	cin >> k;
	v.push_back(k);
	
	for (int i = 0; i < N-1; i++) {
		int a = 0;
		cin >> a;
		v.push_back(a);
	}

	dp.push_back(v[0]);
	for (int i = 1; i < N; i++) {
		if (dp.back() < v[i] ) {
			dp.push_back(v[i]);
		}
		else {
			bfs(v[i]);
		}
	}
	cout << dp.size();
}