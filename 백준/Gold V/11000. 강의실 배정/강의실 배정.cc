#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	priority_queue <int>pq;
	vector<pair<long long int, long long int>>v;
	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		long long int a = 0;
		long long int b = 0;
		cin >> a >> b;
		v.push_back({ -a,-b });
	}

	sort(v.rbegin(), v.rend());

	pq.push(v[0].second);
	long long int answer = 1;
	for (int i = 1; i < v.size(); i++) {
		if (v[i].first > pq.top()) {
			answer++;
			pq.push(v[i].second);
		}
		else {
			pq.pop();
			pq.push(v[i].second);
		}
	}
	cout << answer;
}