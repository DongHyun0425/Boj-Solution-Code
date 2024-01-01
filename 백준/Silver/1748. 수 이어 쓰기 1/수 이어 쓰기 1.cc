#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long int N;
	cin >> N;
	
	int total = 0;

	if (N <= 9) {
		cout << N;
	}
	else {
		for (int i = 1; i <= N; i *= 10) {
			total += N - i + 1;
		}
		cout << total;
	}
	
}