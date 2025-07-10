#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
using namespace std;

int N = 0;
bool map_visited[101][101];
int visit[101][101];
int map[101][101];
int bridge[101][101];
queue<pair<int, pair<int, int>>>q;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<int>candi;

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;
			map[i][j] = tmp;
		}
	}
}

void dfs(int x, int y, int cnt) {
	visit[x][y] = cnt;
	map_visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && !map_visited[nx][ny] && map[nx][ny]==1) {
			dfs(nx, ny, cnt);
		}
	}
}

void make_group() {
	int cnt = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && !map_visited[i][j]) {
				dfs(i, j, cnt);
				cnt++;
			}
		}
	}
}

void make_bridge() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] > 0) {
				q.push({ visit[i][j],{i,j} });
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().second.first;
		int y = q.front().second.second;
		int group = q.front().first;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			//일단 map을 넘지 않아야함
			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				//다리를 연결할수있는경우
				if (visit[nx][ny] == 0) {
					visit[nx][ny] = group;
					bridge[nx][ny] = bridge[x][y] + 1;
					q.push({ group,{nx,ny} });
				}
				else if (visit[x][y]!=visit[nx][ny]) {
					candi.push_back(bridge[x][y] + bridge[nx][ny]);
				}
			}
		}
	}
}


int main() {
	cin >> N;
	init();
	//대륙을 구분하여 visit배열에 넣음
	make_group();
	make_bridge();
	sort(candi.begin(), candi.end());
	cout << candi[0];
}