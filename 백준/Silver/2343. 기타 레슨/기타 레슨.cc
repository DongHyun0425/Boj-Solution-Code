#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable : 4996)

using namespace std;
vector <int>v;
void binearySearch(int Left, int Right,int N,int M) {
	while (Left <= Right) {
		int cnt = 0;
		int result = 0;
		int mid = (Left + Right) / 2;
		for (int i = 0; i < N; i++) {
			result += v[i];
			if (result > mid) { cnt++; result = v[i]; }
		}
		if (result > 0) { cnt++; }
		if (cnt <= M) { Right = mid - 1; }
		else { Left = mid + 1; }
	}
	cout << Left;
}
int main() {
	int N = 0;
	int M = 0;
	cin >> N >> M;
	int Right = 0;
	int Left = 0;
	for (int i = 0; i < N; i++) {
		int a = 0;
		cin >> a;
		if (a > Left) { Left = a; }
		Right += a;
		v.push_back(a);
	}
	binearySearch(Left,Right,N,M);
}