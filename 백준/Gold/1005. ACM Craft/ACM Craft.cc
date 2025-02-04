#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N;
int K;
int Time[1001];
int Dp[1001];
vector<int> graph[1001];
int indegree[1001];
int target;
int Max = 0;

void topologysort() {
	queue<int>q;
	
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) q.push(i);
		Dp[i] = Time[i];
	}

	while (!q.empty()) {
			int now = q.front();
			q.pop();

			for (int i = 0; i < graph[now].size(); i++) {
				int next = graph[now][i];
				indegree[next] -= 1;
				if (Dp[next] < Time[next] + Dp[now]) Dp[next] = Time[next] + Dp[now];
				if (indegree[next] == 0) q.push(next);
			}
	}
}

int main() {
	int T = 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> K;
		for (int j = 1; j <= N; j++) {
			cin >> Time[j];
		}
		for (int j = 0; j < K; j++) {
			int a = 0;
			int b = 0;
			cin >> a >> b;
			graph[a].push_back(b);
			indegree[b] += 1;
		}
		cin >> target;
		topologysort();
		cout << Dp[target] << "\n";

		//초기화
		Max = 0;
		memset(Time, 0, sizeof(Time));
		memset(indegree, 0, sizeof(indegree));
		memset(Dp, 0, sizeof(Dp));
		for (int i = 0; i < 1001; i++) {
			graph[i].clear();
		}

	}
}
