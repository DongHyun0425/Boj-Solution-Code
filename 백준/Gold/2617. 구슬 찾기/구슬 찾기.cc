#include <iostream>
#include <string>
#include <stack>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N = 0;
int M = 0;
int Mid = 0;
int Answer = 0;

vector<int>down[100];
vector<int>up[100];
int arr[100];
int uarr[100];
bool visited[100];

void init() {
	cin >> N >> M;
	Mid = (N + 1) / 2;

	for (int i = 0; i < M; i++) {
		int a = 0;
		int b = 0;
		cin >> a >> b;

		down[a].push_back(b);
		up[b].push_back(a);
	}
}

void d_dfs(int idx,int temp) {
	visited[temp] = true;
	for (int i = 0; i < down[temp].size(); i++) {
		if (!visited[down[temp][i]]) {
			//다음이 노드 2야
			arr[idx]++;
			d_dfs(idx, down[temp][i]);
		}
	}
}

void search_down() {
	for (int i = 1; i <= N; i++) {
		memset(visited, 0, sizeof(visited));
		memset(arr, 0, sizeof(arr));
		d_dfs(i, i);
		if (arr[i] >= Mid)Answer++;
	}
}

void u_dfs(int idx, int temp) {
	visited[temp] = true;
	for (int i = 0; i < up[temp].size(); i++) {
		if (!visited[up[temp][i]]) {
			//다음이 노드 2야
			uarr[idx]++;
			u_dfs(idx, up[temp][i]);
		}
	}
}

void search_up() {
	for (int i = 1; i <= N; i++) {
		memset(visited, 0, sizeof(visited));
		memset(uarr, 0, sizeof(uarr));
		u_dfs(i, i);
		if (uarr[i] >= Mid)Answer++;
	}
}

void solve() {
	//down
	search_down();

	//up
	search_up();

	cout << Answer;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	init();
	solve();
}