#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int map[51][51] = { 0, };
int N, M;
int mymax = 0;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void makemap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char t;
			cin >> t;
			if (t == 'L') {
				map[i][j] = 1;
			}
			else {
				map[i][j] = 0;
			}
		}
	}
}

void BFS(int i, int j) {
	int cnt = 0;
	int visited[51][51] = {0,};
	queue<pair<int, pair<int, int>>>q;
	q.push({ 0, {i, j} });
	visited[i][j] = 1;
	while (!q.empty()) {
		int cost = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		for (int t = 0; t < 4; t++) {
			int nx = x + dx[t];
			int ny = y + dy[t];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny]==1 && visited[nx][ny]==0) {
				visited[nx][ny] = cost + 1;
				q.push({ cost + 1,{nx,ny} });
			}
		}
	}

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			if (visited[x][y] > cnt) {
				cnt = visited[x][y];
			}
		}
	}

	if (cnt > mymax) mymax = cnt;
}

int main() {
	cin >> N >> M;
	makemap();
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				BFS(i, j);
			}
		}
	}
	cout << mymax;
}