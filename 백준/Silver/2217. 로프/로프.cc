#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int N;
	cin >> N;
	vector <int>v;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	vector <int> result;
	int temp = N;
	for (int i = 0; i <N; i++) {
		result.push_back(temp * v[i]);
		temp--;
	}

	sort(result.rbegin(), result.rend());
	cout << result.front();
	return 0;
}