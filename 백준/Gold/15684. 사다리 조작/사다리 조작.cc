#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool ladder_pos[31][31];
int N;
int M;
int H;
int ladder_cnt;
bool flag = false;

void BT(int temp, int cnt) {
	/*if (ladder_pos[0][1] && ladder_pos[0][3] && ladder_pos[1][3] && ladder_pos[2][2] && ladder_pos[2][4] && ladder_pos[3][2] && ladder_pos[4][1] && ladder_pos[4][4]) {
		cout << "hello";
	}*/
	if (cnt == ladder_cnt) {
		for (int i = 1; i <= N; i++) {
			int temp = i;
			int m = i;
			for (int j = 0; j < H; j++) {
				if (ladder_pos[j][m]) {
					temp++;
					m++;
				}
				else if (ladder_pos[j][m - 1]) {
					temp--;
					m--;
				}
			}
			if (temp != i) return;
		}
		flag = true;
		return;
	}


	//사다리 놓기
	for (int x = temp; x < H; x++) {
		for (int i = 1; i < N; i++) {
			if (!ladder_pos[x][i-1] && !ladder_pos[x][i+1] && !ladder_pos[x][i]) {
				ladder_pos[x][i] = true;
				BT(x, cnt + 1);
				ladder_pos[x][i] = false;
			}
		}
	}
}

int main() {
	cin >> N >> M >> H;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		ladder_pos[a-1][b] = true;
	}

	//0,1,2,3 개씩 확인
	for (int i = 0; i <= 3; i++) {
		ladder_cnt = i;
		BT(0, 0);
		if (flag) {
			cout << ladder_cnt;
			break;
		}
	}
	if (!flag) cout << "-1" << "\n";
	return 0;
}