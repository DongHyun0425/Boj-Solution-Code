#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

int LC = 0;
int SC = 0;
int map[101];
queue<pair<int, int>>q;
unordered_map<int, int> um;
int result = 1000000;

void BFS() {
	map[1] = 1;
	q.push({1,0});
	while (!q.empty()) {
		int c_idx = q.front().first;
		int N = q.front().second;
		q.pop();
		if (c_idx == 100 && N < result) {
			result = N;
		}
		for (int i = 1; i <= 6; i++) {
			if (1 <= c_idx + i && c_idx + i <= 100) {
				if (um[c_idx + i] > 0) {
					if (N + 1 < map[um[c_idx + i]]) {
						q.push({ um[c_idx + i],N + 1 });
						map[um[c_idx + i]] = N + 1;
					}
				}
				else {
					if (N + 1 < map[c_idx + i]) {
						q.push({ c_idx + i,N + 1 });
						map[c_idx + i] = N + 1;
					}
				}
			}
		}
	}
}

int main() {
	cin >> LC;
	cin >> SC;
	for (int i = 1; i <= 100; i++) {
		map[i] = 100000;
	}
	for (int i = 0; i < LC + SC; i++) {
		int t1 = 0;
		int t2 = 0;
		cin >> t1;
		cin >> t2;
		um[t1] = t2;
	}

	BFS();
	cout << result;
}