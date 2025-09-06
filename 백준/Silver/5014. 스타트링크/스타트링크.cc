#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int F, S, G, U, D = 0;
bool visited[1000001];
bool flag = false;

void init() {
	cin >> F >> S >> G >> U >> D;
}

void bfs() {
	queue<pair<int,int>>q;
	visited[S] = true;
	q.push({S,0});

	while (!q.empty()) {
		int current = q.front().first;
		int cnt = q.front().second;

		q.pop();

		if (current == G) {
			cout << cnt;
			flag = true;
			return;
		}

		if (current + U >= 1 && current + U <= F && !visited[current + U]) {
			visited[current + U] = true;
			q.push({ current + U,cnt + 1 });
		}

		if (current - D >= 1 && current - D <= F && !visited[current - D]) {
			visited[current - D] = true;
			q.push({ current - D,cnt + 1 });
		}
	}
}

void solve() {
	if (S == G) {
		cout << "0";
	}
	else {
		bfs();
		if (!flag) cout << "use the stairs";
	}
}

int main() {
	init();
	solve();
}