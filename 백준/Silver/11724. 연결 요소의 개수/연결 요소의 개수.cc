#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int visited[1001] = { 0, };
vector <int> v[500001];
int count = 0;

void dfs(int a) {
	visited[a] = 1;
	for (int i = 0; i < v[a].size(); i++) {
		int y = v[a][i];
		if (!visited[y]) {
			dfs(y);
		}
	}
}
int main() {
	long long int N, M = 0;
	cin >> N >> M;
	for (long long int i = 0; i < M; i++) {
		int a = 0;
		int b = 0;
		cin >> a;
		cin >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	long long int count=0;

	for (int i = 1; i < N + 1; i++) {
		if (!visited[i]) {
			count++;
			dfs(i);
		}
	}

	if (M == 0) { cout << N; }
	else {
		cout << count;
	}
}