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

	vector <int> v;
	long long int N, K = 0;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int temp = 0;
		cin >> temp;
		v.push_back(temp);
	}

	int cnt = 0;

	for (int i = v.size()-1; i >= 0; i--) {
			int temp = K / v[i];
			cnt += temp;
			K -= v[i] * temp;
	}
	
	cout << cnt;
}