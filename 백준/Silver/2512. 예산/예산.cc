#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

long long int a[10000];

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0);

	long long int N;
	cin >> N;
	long long int want=0;
	long long int max=0;
	for (int i = 0; i < N; i++) {
		long long int k;
		cin >> k;
		a[i] = k;
		if (k > max) { max = k; }
	}
	cin >> want;
	long long int first = 0;
	long long int last = max;
	long long int find;

	while (first <= last) {
		long long int result = 0;
		long long int mid = (first + last) / 2;
		for (int i = 0; i < N; i++) {
			if (a[i] < mid) { result += a[i]; }
			else { result += mid; }
		}
		if (result <= want) { find = mid; first = mid + 1; }
		else { last = mid - 1; }
	}

	cout << find;
	return 0;
}