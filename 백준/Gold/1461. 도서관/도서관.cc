#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N = 0;
	int Answer = 0;
	int M = 0;
	int Max = 0;
	vector<int>p;
	vector<int>n;

	cin >> N;
	cin >> M;
	for (int i = 0; i < N; i++) {
		int temp = 0;
		cin >> temp;
		if (abs(temp) > Max) Max = abs(temp);

		if (temp < 0) {
			n.push_back(temp);
		}
		else {
			p.push_back(temp);
		}
	}

	sort(p.begin(), p.end(), greater<>());
	sort(n.begin(), n.end());

	for (int i = 0; i < p.size(); i++) {
		if (i % M == 0) {
			Answer += p[i] * 2;
		}
	}

	for (int i = 0; i < n.size(); i++) {
		if (i % M == 0) {
			Answer += abs(n[i]) * 2;
		}
	}

	cout << Answer - Max;
    return 0;
}