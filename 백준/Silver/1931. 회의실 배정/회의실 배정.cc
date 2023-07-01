#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector <pair<int, int>> v;
	int count=1;
	int N;
	int start, finish;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> start >> finish;
		v.push_back(make_pair(finish, start));
	}

	sort(v.begin(), v.end());

	int time=v[0].first;
	for (int i = 1; i < N; i++) {
		if (time <= v[i].second) {
			count++;
			time = v[i].first;
		}
	}
	cout << count;
	return 0;
}