#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

int N = 0;
long long M = 0;

int arr[100005];

void init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}


void solve() {
	int start = 0;
	int end = 0;
	long long sum = arr[0];
	int Answer = 50000;

	while (end < N) {
		//작은경우
		if (sum < M) {
			end++;
			if (end < N)sum += arr[end];
		}
		else if (sum > M) {
			if (end - start < Answer)Answer = end - start;
			if (start < N) sum -= arr[start];
			start++;
		}
		else {
			if (end - start < Answer)Answer = end - start;
			//같은경우, 둘다 이동
			sum -= arr[start];
			start++;
			end++;
			if (end < N)sum += arr[end];
		}
	}
	if (Answer == 50000)cout << "0";
	else cout << Answer+1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	init();
	solve();
}