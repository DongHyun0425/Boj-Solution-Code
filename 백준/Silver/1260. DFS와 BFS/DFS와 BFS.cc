#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool visitedbfs[1001];
bool visiteddfs[1001];
vector<int> graph[1001];

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visitedbfs[start] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << " ";
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (!visitedbfs[y]) {
				q.push(y);
				visitedbfs[y] = true;
			}
		}
	}
}

void dfs(int x) {
	visiteddfs[x] = true;
	cout << x << " ";
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!visiteddfs[y]) dfs(y);
	}
}

int main() {
	int N, M, V = 0;
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 0; i < 1001; i++) {
		sort(graph[i].begin(),graph[i].end());
	}
	dfs(V);
	cout << "\n";
	bfs(V);
	return 0;
}