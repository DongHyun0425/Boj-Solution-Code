#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

int N = 0;
int M = 0;
double Answer = 0;
vector<pair<int, int>>pos;
vector<pair<double, pair<int, int>>>v;
int parent[1005];

int find_parent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find_parent(parent[x]);
}

void merge(int x, int y) {
	int a = find_parent(x);
	int b = find_parent(y);

	parent[b] = a;
}

void init() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int x = 0;
		int y = 0;
		cin >> x >> y;
		pos.push_back({ x,y });
		parent[i] = i;
	}

	for (int i = 0; i < pos.size(); i++) {
		for (int j = 0; j < pos.size(); j++) {
			if (i == j)continue;
			int x = pos[i].first;
			int y = pos[i].second;
			int a = pos[j].first;
			int b = pos[j].second;

			double cost = sqrt(pow((x - a), 2) + pow((y - b), 2));
			v.push_back({ cost,{ i,j } });
		}
	}

	//merge
	for (int i = 0; i < M; i++) {
		int a = 0;
		int b = 0;
		cin >> a >> b;
		merge(a-1, b-1);
	}
}

void solve() {
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		double cost = v[i].first;
		int a = v[i].second.first;
		int b = v[i].second.second;

		if (find_parent(a) != find_parent(b)) {
			merge(a, b);
			Answer += cost;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	init();
	solve();
	cout<<fixed;
	cout.precision(2);
	cout << round(Answer*100)/100;
}