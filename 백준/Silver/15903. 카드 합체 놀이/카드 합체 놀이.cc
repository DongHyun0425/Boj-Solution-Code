#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <queue>
#include <iostream>
using namespace std;

int main() {
	int n = 0;
	int m = 0;
	cin >> n >> m;

	vector<long long>v;

	for (int i = 0; i < n; i++) {
		int tmp = 0;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < m; i++) {
		long long tmp = v[0] + v[1];
		v[0] = tmp;
		v[1] = tmp;
		sort(v.begin(), v.end());
	}
	
	long long int answer = 0;
	for (int i = 0; i < v.size(); i++) {
		answer += v[i];
	}
	cout << answer;

}