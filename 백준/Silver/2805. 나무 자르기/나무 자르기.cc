#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

long long int N[1000000];

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0);

	long num = 0;
	long long result = 0;
	cin >> num;
	cin >> result;
	
	long first = 0;
	long last=0;
	long mid;

	for (int i = 0; i < num; i++) {
		long long int a;
		cin >> a;
		N[i] = a;

		if (a > last) {
			last = a;
		}
	}

	long long int k = 0;
	while (first<=last) {
		mid = (first + last) / 2;
		long long int want = 0;
		for (int i = 0; i < num; i++) {
			if (N[i] > mid) { want += N[i] - mid; }
		}
		if (want < result) {
			last = mid - 1;
		}
		else {
			k = mid;
			first = mid + 1;
		}
	}
	cout << k;
	return 0;
}