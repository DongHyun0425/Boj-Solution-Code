#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<pair<int, int>>graph[1001];
int d[1001] = { 0, };
void dij(int start) {
	priority_queue <pair<int, int>>pq;
	pq.push({ 0,start });
	d[start] = 0;
	while (!pq.empty()) {
		int now = pq.top().second;
		int dist = -pq.top().first;

		pq.pop();

		if (d[now] < dist) continue;

		for (int i = 0; i < graph[now].size(); i++) {
			int cost = dist + graph[now][i].second;
			if (cost < d[graph[now][i].first]) {
				pq.push({ -cost , graph[now][i].first });
				d[graph[now][i].first] = cost;
			}
		}
	}
}
int main() {
	cin >> N; 
	cin>> M;
	for (int i = 0; i < M; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		graph[start].push_back({ end,cost });
	}
	fill(d, d + 1001, 987654321);
	int start, target;
	cin >> start >> target;
	dij(start);
	cout << d[target];
}