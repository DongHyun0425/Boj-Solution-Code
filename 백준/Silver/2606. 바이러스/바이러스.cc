#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

queue <int> q;
vector <int> graph[101];
bool visited[101] = { 0 };

void bfs(int node) {
	q.push(node);
	visited[node] = 1;
	while (q.size()>0) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < graph[x].size(); i++) {
			if (!visited[graph[x][i]]) {
				q.push(graph[x][i]);
				visited[graph[x][i]] = 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	
	int c = 0;
	cin >> c;
	
	for (int i = 0; i < c; i++) {
		int n;
		int k;
		cin >> n >> k;
		graph[n].push_back(k);
		graph[k].push_back(n);
	}

	bfs(1);
	int cnt = 0;
	for (int i = 1; i < n+1; i++) {
		if (visited[i] == 1) { cnt++; }
	}
	cout << cnt-1;
}