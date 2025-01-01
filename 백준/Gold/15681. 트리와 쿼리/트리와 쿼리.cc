#include <iostream>
#include <queue>
using namespace std;

int N = 0;
int R = 0;
int Q = 0;

vector<int> graph[1000000];
int cc[1000000];
bool visited[1000000];

int dfs(int a) {
	visited[a] = true;
	cc[a] = 1;
	for (int i = 0; i < graph[a].size(); i++) {
		if (!visited[graph[a][i]]) {
			cc[a] += dfs(graph[a][i]);
		}
	}
	return cc[a];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	cin >> R;
	cin >> Q;

	for (int i = 0; i < N - 1; i++) {
		int tmp1 = 0;
		int tmp2 = 0;
		cin >> tmp1;
		cin >> tmp2;

		graph[tmp1].push_back(tmp2);
		graph[tmp2].push_back(tmp1);
	}

	dfs(R);
	for (int i = 0; i < Q; i++) {
		int temp = 0;
		cin >> temp;
		cout << cc[temp] << "\n";
	}
}
