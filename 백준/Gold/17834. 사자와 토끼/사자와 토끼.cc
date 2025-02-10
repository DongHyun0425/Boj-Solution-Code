#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int N;
int M;
vector<int> graph[50001];
int visited[50001];
int Red;
int Blue;

void DFS(int start) {
	if (visited[start] == 0) {
		visited[start] = 2;
		Red++;
	}
	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];
		if (visited[next] == 0) {
			if (visited[start] == 2) {
				Blue++;
				visited[next] = 3;
			}
			else {
				Red++;
				visited[next] = 2;
			}
			DFS(next);
		}
	}
}

int check() {
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			int next = graph[i][j];
			if (visited[next] == visited[i]) return false;
		}
	}
	return true;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a = 0;
		int b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	DFS(1);

	if (check()) {
		cout << Red * Blue * 2;
	}
	else {
		cout << 0;
	}
	
}