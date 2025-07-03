#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

long v[300001];
vector<int>a;
int N;
int K;
int main() {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		long tmp;
		cin >> tmp;
		v[i] = tmp;
		if (i > 0) {
			a.push_back(v[i] - v[i - 1]);
		}
	}

	sort(a.begin(),a.end());

	long answer=0;
	for (int i = 0; i < N - K; i++) {
		answer += a[i];
	}

	cout << answer;

}