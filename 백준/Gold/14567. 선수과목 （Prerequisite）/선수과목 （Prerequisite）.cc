#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int indegree[10001];
vector<int> graph[500001];
int result[10001];
int main() {
	
	queue <int> q;
	int N, M;
	cin >> N >> M;

	for (int i = 1; i < 10001; i++) {
		result[i] = 1;
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		indegree[b]++;
	}


	for (int i = 1; i <= N; i++) {
		//맨처음에는 진입차수가 0인애들만 전부 q에 넣음
		//그 다음부터 만약 진입차수가 없으면 q에 삽입 그다음에 뽑고 다음 간선 노드 진입차수 0만들기
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			indegree[graph[now][i]] -= 1;
			//그리고 새롭게 진입차수가 0되는애들 q에 넣기
			if (indegree[graph[now][i]] == 0) {
				result[graph[now][i]] = result[now]+1;
				q.push(graph[now][i]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << result[i] << " ";
	}
}
