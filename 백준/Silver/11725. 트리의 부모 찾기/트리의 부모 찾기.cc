#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector <int> graph[100001];
int parent[100001];
int visited[100001];
queue<int>q;

void bfs(int start) {
	q.push(start);
	visited[start] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (!visited[y]) {
				q.push(y);
				visited[y] = true;
				parent[y] = x;
			}
		}
	}
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N-1; i++) {
		int a, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	bfs(1);
	for (int i = 2; i < N+1; i++) {
		cout << parent[i] << "\n";
	}
}