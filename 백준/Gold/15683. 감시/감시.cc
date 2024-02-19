#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int map[8][8] = { 0, };
int camerasize = 0;
vector<pair<int, int>>camera;
int cameratype[9] = { 0, };
int minimum = 987654321;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int checkmap() {
	int tmp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				tmp++;
			}
		}
	}
	return tmp;
}

void make_map(int d, int cx, int cy) {
	while (1) {
			int nx = cx + dx[d];
			int ny = cy + dy[d];
			if (nx >= 0 && nx < N && ny >=0 && ny < M && map[nx][ny]!=6) {
				if (map[nx][ny] == 0) {
					map[nx][ny] = -1;
				}
				else if (map[nx][ny] <6) {
					cx = nx;
					cy = ny;
					continue;
				}
			}
			else {
				break;
			}
			cx = nx;
			cy = ny;
		}
}

void dfs(int cnt) {
	if (cnt == camerasize) {
		int tmp = checkmap();
		if (tmp < minimum) {
			minimum = tmp;
		}
		return;
	}

	for (int d = 0; d < 4; d++) {
		int type = cameratype[cnt];

		int tmp_map[8][8] = { 0, };
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				tmp_map[i][j] = map[i][j];
			}
		}

		if (type == 1) {
			make_map(d, camera[cnt].first, camera[cnt].second);
		}
		else if (type == 2) {
			make_map(d, camera[cnt].first, camera[cnt].second);
			make_map((d + 2) % 4, camera[cnt].first, camera[cnt].second);

		}
		else if (type == 3) {
			make_map(d, camera[cnt].first, camera[cnt].second);
			make_map((d + 1) % 4, camera[cnt].first, camera[cnt].second);
		}
		else if (type == 4) {
			make_map(d, camera[cnt].first, camera[cnt].second);
			make_map((d + 1) % 4, camera[cnt].first, camera[cnt].second);
			make_map((d + 2) % 4, camera[cnt].first, camera[cnt].second);
		}
		else if (type == 5) {
			make_map(d, camera[cnt].first, camera[cnt].second);
			make_map((d + 1) % 4, camera[cnt].first, camera[cnt].second);
			make_map((d + 2) % 4, camera[cnt].first, camera[cnt].second);
			make_map((d + 3) % 4, camera[cnt].first, camera[cnt].second);
		}


		dfs(cnt + 1);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				map[i][j] = tmp_map[i][j];
			}
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int tmp = 0;
			cin >> tmp;
			if (tmp != 0 && tmp !=6) {
				camera.push_back({ i,j });
				cameratype[camerasize] = tmp;
				camerasize++;
			}
			map[i][j] = tmp;
		}
	}
	dfs(0);

	cout << minimum;
}