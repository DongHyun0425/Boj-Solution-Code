#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>>graph[300001];
int N, M, K, X;
int d[300001] = { 0, };
void dij(int start) {
	priority_queue<pair<int, int>>pq;
	pq.push({ 0,start });
	d[start] = 0;

	while (!pq.empty()) {
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (d[now] < dist) continue;

		for (int i = 0; i < graph[now].size(); i++) {
			int cost = dist + graph[now][i].second;
			if (cost < d[graph[now][i].first]) {
				d[graph[now][i].first] = cost;
				pq.push({ -cost,graph[now][i].first });
			}
		}
	}
}

int main() {
	cin >> N >> M >> K >> X;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back({ b,1 });
	}

	fill(d, d + 300001, 100000);

	dij(X);


	int flag = 0;
	for (int i = 1; i <= N; i++) {
		if (d[i] == K) { 
			cout << i << "\n";  
			flag++; 
		}
	}

	if (flag==0) {
		cout << -1;
	}
}