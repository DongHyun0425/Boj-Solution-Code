#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

vector<int>v[35000];
int degree[35000];
priority_queue<int, vector<int>, greater<int>> pq;

int N = 0;
int M = 0;

void init() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a = 0;
		int b = 0;
		cin >> a >> b;

		v[a].push_back(b);
		degree[b]++;
	}
}
void solve() {
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) pq.push(i);
	}
	
	//간선끊기
	while (!pq.empty()) {
		int now = pq.top();
		cout << now << " ";
		pq.pop();

		for (int i = 0; i < v[now].size(); i++) {
			degree[v[now][i]]--;
			if (degree[v[now][i]] == 0) pq.push(v[now][i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	init();
	solve();
}