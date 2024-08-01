#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
vector<int> graph[200001];
int visited[200001];

void dfs(int start, int color) {
	if (!visited[start]) {
		if (color == 1) {
			visited[start] = 1;
		}
		else {
			visited[start] = 2;
		}
	}

	for (int i = 0; i < graph[start].size(); i++) {
		if (!visited[graph[start][i]]) {
			if (color == 1) {
				dfs(graph[start][i], 2);
			}
			else {
				dfs(graph[start][i], 1);
			}
		}
	}
}

int main() {
	int K = 0;
	cin >> K;

	for (int i = 0; i < K; i++) {
		int V = 0;
		int E = 0;
		cin >> V >> E;
		for (int j = 0; j < E; j++) {
			int a = 0;
			int b = 0;
			cin >> a >> b;

			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		for (int j = 1; j <= V; j++) {
			if (visited[j] == 0) {
				dfs(j, 1);
			}
		}

		bool flag = true;
		for (int i = 1; i <= V; i++) {
			int c = visited[i];
			for (int j = 0; j < graph[i].size(); j++) {
				if (visited[graph[i][j]] == c) {
					flag = false;
					break;
				}
			}
			if (!flag) break;
		}

		if (!flag) {
			cout << "NO"<<"\n";
		}
		else {
			cout << "YES"<<"\n";
		}

		for (int i = 0; i <= V; i++) {
			graph[i].clear();
		}
		memset(visited, false, sizeof(visited));
		
	}
}