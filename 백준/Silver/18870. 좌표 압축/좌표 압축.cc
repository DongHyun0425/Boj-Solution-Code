#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
vector<pair<int, int>>v;
vector<pair<int, int>>result;
int cnt = 0;
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		v.push_back({ k,i });
	}
	
	sort(v.begin(), v.end());

	result.push_back({v[0].second,0});

	for (int i = 1; i < N; i++) {
		if (v[i - 1].first == v[i].first) {
			result.push_back({ v[i].second,cnt });
		}
		else {
			result.push_back({ v[i].second,++cnt });
		}
	}

	sort(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++) {
		cout << result[i].second << " ";
	}
	return 0;
}