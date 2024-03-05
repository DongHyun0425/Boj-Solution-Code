#include <iostream>
#include <queue>
using namespace std;

int map[51][51] = { 0, };
int N, M;
int dx[9] = { 0,0,-1,-1,-1,0,1,1,1 };
int dy[9] = { 0,-1,-1,0,1,1,1,0,-1 };
queue<pair<int, int>> cloud;
void makemap() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int tmp = 0;
			cin >> tmp;
			map[i][j] = tmp;
		}
	}
}

void movecloud() {
	int d = 0;
	int s = 0;
	cin >> d >> s;
	for (int i = 0; i < cloud.size(); i++) {
		int cx = cloud.front().first;
		int cy = cloud.front().second;
		cloud.pop();
		for (int j = 0; j < s; j++) {
			cx += dx[d];
			cy += dy[d];
			if (cx == 0) cx = N;
			if (cx == N + 1) cx = 1;
			if (cy == 0) cy = N;
			if (cy == N + 1) cy = 1;
		}
		cloud.push({ cx,cy });
	}
}

void plusone() {
	for (int i = 0; i < cloud.size(); i++) {
		int cx = cloud.front().first;
		int cy = cloud.front().second;
		cloud.pop();
		map[cx][cy] += 1;
		cloud.push({ cx,cy });
	}
}

void pluscloud() {

	int tmpmap[51][51] = { 0, };
	for (int x = 0; x < 51; x++) {
		for (int y = 0; y < 51; y++) {
			tmpmap[x][y] = map[x][y];
		}
	}

	for (int i = 0; i < cloud.size(); i++) {

		int cx = cloud.front().first;
		int cy = cloud.front().second;

		//북서방향
		if (cx - 1 >= 1 && cy - 1 >= 1 && map[cx-1][cy-1] > 0) {
			tmpmap[cx][cy] += 1;
		}
		//북동방향
		if (cx - 1 >= 1 && cy + 1 <= N && map[cx-1][cy+1] > 0) {
			tmpmap[cx][cy] += 1;
		}//남서방향
		if (cx +1 <= N && cy - 1 >= 1  && map[cx+1][cy-1] > 0) {
			tmpmap[cx][cy] += 1;
		}//남동방향
		if (cx + 1 <= N && cy + 1 <= N && map[cx+1][cy+1] > 0) {
			tmpmap[cx][cy] += 1;
		}

		cloud.pop();
		cloud.push({ cx,cy });
	}

	for (int x = 0; x < 51; x++) {
		for (int y = 0; y < 51; y++) {
			map[x][y] = tmpmap[x][y];
		}
	}
}

void makenewcloud() {
	bool cloudtrue[51][51] = {};
	int s = cloud.size();
	for (int i = 0; i < s; i++) {
		int cx = cloud.front().first;
		int cy = cloud.front().second;
		cloud.pop();
		cloudtrue[cx][cy] = true;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] >= 2 && !cloudtrue[i][j]) {
				map[i][j] -= 2;
				cloud.push({ i,j });
			}
		}
	}
}

int main() {
	cin >> N >> M;
	//1번
	makemap();
	//초기구름위치설정
	cloud.push({ N,1 });
	cloud.push({ N,2 });
	cloud.push({ N-1,1 });
	cloud.push({ N-1,2 });

	for (int t = 0; t < M; t++) {
		//2번
		movecloud();
		//3번--구름1만큼추가
		plusone();
		//4번--구름 흡성대법
		pluscloud();
		//5번--구름제외 2이상 구름make,물양-2
		makenewcloud();
	}

	int answer = 0;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			answer += map[i][j];
		}
	}
	cout << answer;
	return 0;
}