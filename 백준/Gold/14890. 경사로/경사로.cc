#include <iostream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
using namespace std;

int N = 0;
int L = 0;
int map[100][100];
int tempmap[100][100];
int gap[100][100];
int answer = 0;

void solution() {
	for (int i = 0; i < N; i++) {
		int start = map[i][0];
		bool jul = true;
		for (int j = 1; j < N; j++) {
			int comp = map[i][j];
			if (start == comp) continue;
			if (start + 1 == comp) {
				//<-빡구로 확인
				bool flag = true;
				for (int x = 1; x <= L; x++) {
					if ((comp != map[i][j - x] + 1) || gap[i][j - x] == 1 || j - x < 0) {
						flag = false;
						break;
					}
				}
				if (flag) {
					for (int x = 1; x <= L; x++) {
						gap[i][j - x] = 1;
					}
					start = comp;
					continue;
				}
				//건설불가
				jul = false;
				break;
			}
			if (start - 1 == comp) {
				//->로 확인
				bool flag = true;
				for (int x = 0; x < L; x++) {
					if ((start != map[i][j + x] + 1) || gap[i][j + x] == 1 || j + x >= N) {
						flag = false;
						break;
					}
				}
				if (flag) {
					for (int x = 0; x < L; x++) {
						gap[i][j + x] = 1;
					}
					start = comp;
					continue;
				}
				//건설불가
				jul = false;
				break;
			}
			jul = false;
			break;
		}
		if (jul == true) answer++;
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				gap[a][b] = 0;
			}
		}
	}
}

int main() {
	cin >> N;
	cin >> L;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp = 0;
			cin >> tmp;
			map[i][j] = tmp;
		}
	}

	//->  확인
	solution();
	//배열 돌리기

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) tempmap[N - 1 - j][i] = map[i][j];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) map[i][j] = tempmap[i][j];
	}
	solution();
	
	cout << answer;
}