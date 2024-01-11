#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
#include <tuple>

using namespace std;

int map[51][51] = { 0 };
bool check[51][51];
int total = 0;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	int N, M, r,c,d = 0;
	cin >> N >> M;
	cin >> r >> c >> d;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int temp = 0;
			cin >> temp;
			map[i][j] = temp;
		}
	}

	
	while (1) {
		if (check[r][c] == false) {
			check[r][c] = true;
			total++;
		}

		bool ch=false;

		for (int i = 0; i < 4; i++) {
			d = (d + 3) % 4;
			int nr = r + dx[d];
			int nc = c + dy[d];
			if (map[nr][nc] == 0 && check[nr][nc]==false) {
				r += dx[d] ;
				c += dy[d];
				ch = true;
				break;
			}
		}
		if (!ch) {
			int back = (d + 2) % 4;
			if (map[r + dx[back]][c + dy[back]] == 1) {
				break;
			}
			else {
				r += dx[back];
				c += dy[back];
			}
		}
	}
	cout << total;
}