#include <iostream>
#include <queue>
using namespace std;

//벽부수고 이동하기 //강의실 배정

int map[1001][1001] = { 0, };
int visited[1001][1001][2];
int minimum = 1000001;
int N, M;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int bfs(int x, int y) {
	queue<pair<pair<int, int>, int>>q;
	q.push({ {1,1},1 });
	visited[1][1][1] = 1;

	while (!q.empty()) {
		int cr = q.front().first.first;
		int cc = q.front().first.second;
		int block = q.front().second;
		q.pop();

		if (cr == N && cc == M) {
			return visited[cr][cc][block];
		}

		for (int i = 0; i < 4; i++) {
			int nextr = cr + dx[i];
			int nextc = cc + dy[i];
			if (nextr >= 1 && nextr <= N && nextc >= 1 && nextc <= M) {
				if (map[nextr][nextc] == 1 && block) {
					q.push({ { nextr,nextc }, 0 });
					//현재까지의 block안뚫은 1에서 1을 더해서 block뚫은 0에다가 넣음
					visited[nextr][nextc][block - 1] = visited[cr][cc][block] + 1;
				}
				else if (map[nextr][nextc] == 0 && visited[nextr][nextc][block] == 0) {
					q.push({ {nextr,nextc},block });
					visited[nextr][nextc][block] = visited[cr][cc][block] + 1;
				}
				
			}
		}
	}
	return -1;
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string tmp = "";
		cin >> tmp;
		for (int j = 1; j <= M; j++) {
			map[i][j] = tmp[j - 1] - '0';
		}
	}

	cout<<bfs(1, 1)<<"\n";
	
	return 0;
}