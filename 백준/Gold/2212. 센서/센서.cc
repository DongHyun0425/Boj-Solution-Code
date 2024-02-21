#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N;
	cin >> M;
	vector<int>sensor;
	vector <int> gap;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		if (find(sensor.begin(), sensor.end(), tmp) == sensor.end()) {
			sensor.push_back(tmp);
		}
	}
	sort(sensor.begin(), sensor.end());

	for (int i = 0; i < sensor.size()-1; i++) {
		gap.push_back(sensor[i + 1] - sensor[i]);
	}
	sort(gap.rbegin(), gap.rend());

	int answer = 0;

	for (int i = M-1; i < gap.size(); i++) {
		answer += gap[i];
	}
	cout << answer;
}