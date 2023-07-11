#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N = 0;
	cin >> N;
	vector <int> v;
	for (int i = 0; i < N; i++) {
		int a = 0;
		cin >> a;
		v.push_back(a);
	}

	int M;
	cin >> M;

	sort(v.begin(), v.end());

	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		if (binary_search(v.begin(), v.end(), a)) { cout << 1 << '\n'; }
        else { cout << 0 << '\n'; }
	}
	return 0;
}