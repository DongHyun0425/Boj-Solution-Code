#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int parent[100001];

int findParent(int x) {
	if (parent[x] == x) { return x; }
	else { 
		return parent[x]=findParent(parent[x]); 
	}
}

void unionFind(int a,int b) {
	if (findParent(a) < findParent(b)) {
		parent[findParent(b)] = findParent(a);
	}
	else {
		parent[findParent(a)] = findParent(b);
	}
}

int main() {
	int N, M;
	vector<pair<int, pair<int, int>>> edge;
	int result = 0;
	cin >> N >> M;
	int max = 0;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back({ c,{a,b} });
	}

	sort(edge.begin(), edge.end());

	for (int i = 1; i <=N; i++) {
		parent[i] = i;
	}

	for (int i=0; i < M; i++) {
		int cost = edge[i].first;
		int a = edge[i].second.first;
		int b = edge[i].second.second;

		if (findParent(a) != findParent(b)) {
			if (cost > max) { max = cost; }
			result += cost;
			unionFind(a, b);
		}
	}
	cout << result-max;
}