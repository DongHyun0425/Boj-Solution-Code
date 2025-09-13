#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int Dist[130][130];
int N;
bool Flag;
int Answer;
int MAP[130][130];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void init() {
	for (int i = 0; i < 130; i++) {
		for (int j = 0; j < 130; j++) {
			Dist[i][j] = 987654321;
		}
	}
}

void input() {
	cin >> N;
	if (N == 0) {
		Flag = true;
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}
}

void solution() {
	priority_queue<pair<int, pair<int, int>>> pq;// 뒤에 x,y좌표
	pq.push({ -MAP[0][0],{0,0} });
	Dist[0][0] = MAP[0][0];

	while (pq.empty() == 0) {
		int Cost = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;

		pq.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
				int nCost = Cost + MAP[nx][ny];
				if (Dist[nx][ny] > nCost) {
					Dist[nx][ny] = nCost;
					pq.push({ -Dist[nx][ny],{nx,ny} });
				}
			}
		}
	}
	Answer = Dist[N - 1][N - 1];
}

void solve() {
	int Tc = 1;
	for (int T = 1;; T++) {
		init();
		input();
		if (Flag == true) return;
		solution();
		cout << "Problem " << T << ": " << Answer << "\n";
	}
}

int main() {
	solve();
}