#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

int N = 0;
int M = 0;
bool arr[32005] = {false,};
int indegree[32005];
vector<int>v[32005];
priority_queue<int>pq;

void init() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a = 0;
		int b = 0;
		cin >> a >> b;
		arr[a] = true;
		arr[b] = true;
		indegree[b]++;
		v[a].push_back(b);
	}
}


void solve() {
	//일단 조건에 없는애들 전부 출력
	for (int i = 1; i <= N; i++) {
		if (!arr[i]) cout << i << " ";
		else {
			if (indegree[i] == 0) pq.push(i);
		}
	}

	//차수가 0인것부터 확인
	while (!pq.empty()) {
		int node = pq.top();
		cout << node << " ";
		pq.pop();

		for (int i = 0; i < v[node].size(); i++) {
			int nxt = v[node][i];
			indegree[nxt]--;
			if (indegree[nxt] == 0)pq.push(nxt);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	init();
	solve();
}