#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<pair<int, int>>v;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());

	vector<pair<int, int>>v1;
	for (int i = 0; i < v.size(); i++) {
		v1.push_back({ v[i].second,0 });
	}
	int mymax = 0;
	for (int i = 0; i < v1.size(); i++) {
		int cnt = 0;
		for (int j = 0; j < i; j++) {
			if (v1[j].first < v1[i].first && cnt < v1[j].second) {
				cnt = v1[j].second;
			}
		}
		v1[i].second = cnt+1;
		if (mymax < v1[i].second) {
			mymax = v1[i].second;
		}
	}

	cout << N-mymax;
}