#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
using namespace std;

int board[1000][1000];
long long d[1000][1000];

int N;
int M;
int ti = 0;
int tj = 0;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
queue<pair<pair<int, int>, int>>q;

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int temp = 0;
			cin >> temp;
			board[i][j] = temp;

			//벽
			if (temp == 0) d[i][j] = 10000;
			//target
			if (temp == 2) {
				ti = i;
				tj = j;
				d[i][j] = 10000;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N>>M;
	init();

	q.push({ {ti,tj},1 });

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;

		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M && d[nx][ny] == 0) {
				d[nx][ny] = cnt;
				q.push({ {nx,ny},cnt + 1 });
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (d[i][j] == 10000) { cout << "0" << " "; continue; }
			if (d[i][j] == 0 && board[i][j] == 1) { cout << "-1" << " "; continue; }
			cout << d[i][j] << " ";
		}
		cout << "\n";
	}
}