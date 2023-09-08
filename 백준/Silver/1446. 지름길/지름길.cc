#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N, D = 0;
	cin >> N >> D;
	vector <int> map(10001, 10001);
	vector <pair<int, int>> j[10001];
	for (int i = 0; i < N; i++) {
		int start, end, dis = 0;
		cin >> start >> end >> dis;
		j[end].push_back({ start,dis });
	}

	map[0] = 0;

	for (int i = 1; i < D+1; i++) {
		if (j[i].size() == 0) { map[i] = map[i - 1] + 1; }
		else {
			for (auto v:j[i]) {
				map[i] = min(map[i], min(map[i-1]+1,map[v.first]+v.second));
			}
		}
	}
	cout << map[D];

}