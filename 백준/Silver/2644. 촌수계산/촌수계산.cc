#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

vector <int> v[102];
int a, b = 0;
int visited[102];
queue<int>q;
void bfs(int start) {
	q.push(start);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i];
			if (visited[y] == 0) {
				q.push(y);
				visited[y] += visited[x]+1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;
	
	cin >> a >> b;
	int k = 0;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int x, y = 0;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	bfs(a);
	if (visited[b] == 0) {
		cout << "-1";
	}
	else {
		cout << visited[b];
	}
}