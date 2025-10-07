#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

int T = 0;

void solve() {
	int N, M, W = 0;
	vector<pair<pair<int, int>, int>>Edge;
	int Dist[501] = { 0, };
	memset(Dist, 30000000, sizeof(Dist));

	cin >> N >> M >> W;

	for (int i = 0; i < M; i++) {
		int s, e, t = 0;
		cin >> s >> e >> t;

		Edge.push_back({ {s,e},t });
		Edge.push_back({ {e,s},t });		
	}

	for (int i = 0; i < W; i++) {
		int s, e, t = 0;
		cin >> s >> e >> t;

		Edge.push_back({ {s,e},-t });
	}

	//Bellman_Ford()
	Dist[1] = 0;
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 0; j < Edge.size(); j++) {
			int From = Edge[j].first.first;
			int To = Edge[j].first.second;
			int Cost = Edge[j].second;

			if (Dist[To] > Dist[From] + Cost) Dist[To] = Dist[From] + Cost;
		}
	}

	for (int j = 0; j < Edge.size(); j++) {
		int From = Edge[j].first.first;
		int To = Edge[j].first.second;
		int Cost = Edge[j].second;

		if (Dist[To] > Dist[From] + Cost) {
			cout << "YES" << "\n";
			return;
		}
	}
	cout << "NO" << "\n";
}

void init() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		solve();
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	init();
}