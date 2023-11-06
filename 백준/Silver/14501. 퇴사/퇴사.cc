#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;


int main() {
	int N;
	cin >> N;
	int T[16] = {0};
	int P[16] = { 0 };
	for (int i = 1; i <= N; i++) {
		int a, b = 0;
		cin >> a;
		cin >> b;
		if (a + i <= N + 1) {
			T[i]=a;
			P[i]=b;
		}
	}

	int A[16] = { 0 };
	int max = 0;

	for (int i = 1; i <= N; i++) {
		int smax = 0;
		for (int k = 1; k < i; k++) {
			if (smax < A[k]) {
				smax = A[k];
			}
		}

		int a = smax + P[i];

		if (a > max) {
			max = a;
		}

		if (a > A[T[i] + i - 1]) {
			A[T[i] + i - 1] = a;
		}
	}
	cout << max;
}