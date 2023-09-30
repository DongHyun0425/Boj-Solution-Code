#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
long long int N = 0;

void check(long long int one, long long int zero, long long int n) {
	long long int One = 0;
	long long int Zero = 0;

	One += zero;
	Zero += (one + zero);
	n += 1;
	if (n == N) {
		cout << One + Zero;
	}
	else {
		check(One, Zero, n);
	}
}

int main() {
	
	cin >> N;

	if (N == 1 || N == 2) { cout << 1; }
	else {
		check(0, 1, 2);
	}
}