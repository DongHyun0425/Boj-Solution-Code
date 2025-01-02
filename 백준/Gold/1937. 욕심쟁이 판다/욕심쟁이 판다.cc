#include <iostream>
#include <queue>
using namespace std;

int N = 0;
int Answer = 0;
int map[500][500];
int DP[500][500];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int dfs(int i, int j) {
	//왜냐하면 DP를 방문했을때 0이 아니라면 이미 해당 좌표에서 이동할수있는 최대값이 갱신되어 있기 때문
	if (DP[i][j] != 0) return DP[i][j];
	//DP[i][j]에 처음 오면 어차피 하루는 살기 때문에 1로 설정
	DP[i][j] = 1;

	for (int x = 0; x < 4; x++) {
		int nx = i + dx[x];
		int ny = j + dy[x];

		if (nx >= 0 && ny >= 0 && nx < N && ny < N && (map[i][j]<map[nx][ny])) {
			int temp = dfs(nx, ny) + 1;
			if (DP[i][j] < temp) DP[i][j] = temp;
		}
	}

	return DP[i][j];
}

int main() {
	cin >> N;

	//맵 받기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp = 0;
			cin >> temp;
			map[i][j] = temp;
		}
	}

	//dfs돌기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp = dfs(i, j);
			if (Answer < temp) Answer = temp;
		}
	}
	cout << Answer;
}