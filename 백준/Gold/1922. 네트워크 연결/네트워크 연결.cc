#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int parent[100001];

int findParent(int x) {
	if (parent[x] == x) {
		return x;
	}
	else {
		return parent[x] = findParent(parent[x]);
	}
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a < b) { parent[b] = a; }
	else parent[a] = b;
}

int main() {
	int N = 0;
	int M = 0;
	cin >> N >> M;

	vector<pair<int, pair<int, int>>> edge;
	int result = 0;

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		edge.push_back({ cost,{a,b} });
	}

	sort(edge.begin(), edge.end());

	for (int i = 0; i < M; i++) {
		int cost = edge[i].first;
		int start = edge[i].second.first;
		int end = edge[i].second.second;

		if (findParent(start) != findParent(end)) {
			result += cost;
			unionParent(start, end);
		}
	}

	cout << result << "\n";
}