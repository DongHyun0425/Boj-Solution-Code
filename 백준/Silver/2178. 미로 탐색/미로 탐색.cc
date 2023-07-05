#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int map[100][100];
queue <pair<int, int>> q;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n = 0; 
int m = 0;
void bfs() {
	q.push({ 0,0 });
	while (q.size() > 0) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x_new = x + dx[i];
			int y_new = y + dy[i];
			if (0 > x_new || x_new >= n || y_new < 0 || y_new >= m ) {
				continue;
			}
			if (map[x_new][y_new] == 0) { continue; }
			if (map[x_new][y_new] == 1) {
				map[x_new][y_new] = map[x][y] + 1;
				q.push({ x_new,y_new });
			}
		}
	}
	cout << map[n-1][m-1];
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; 
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = s[j]-'0';
		}
	}
	bfs();
}