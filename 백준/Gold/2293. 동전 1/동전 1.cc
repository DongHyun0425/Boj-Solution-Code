#include <iostream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
using namespace std;

int n, sum, ans;
vector<int> coin;
int DP[10001];
int main() {
	cin >> n;
	cin >> sum;
	for (int i = 0; i < n; i++) {
		int temp = 0;
		cin >> temp;
		coin.push_back(temp);
	}
	sort(coin.begin(), coin.end());

	DP[0] = 1;

	for (int i = 0; i < n; i++) {
		int currentCoin = coin[i];
		for (int j = currentCoin; j <= sum; j++) {
			DP[j] = DP[j] + DP[j - currentCoin];
		}
	}
	cout << DP[sum];
}