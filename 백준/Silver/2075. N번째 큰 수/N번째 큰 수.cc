#include <iostream>
#include <queue>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int>pq;
	int N;
	cin >> N;
	for (int i = 0; i < N * N; i++) {
		int temp;
		cin >> temp;

		pq.push(-temp);

		if (pq.size() > N) {
			pq.pop();
		}
	}

	cout << -pq.top();
}
