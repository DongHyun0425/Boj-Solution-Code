#include <iostream>
using namespace std;

int main() {
	int N = 0;
	int cnt = 0;
	cin >> N;
	N = 1000 - N;
	int a[6] = { 500,100,50,10,5,1 };
	for (int i = 0; i < 6; i++) {
		cnt += N / a[i];
		N = N % a[i];
	}
	cout << cnt;

	return 0;
}