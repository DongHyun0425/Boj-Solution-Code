#include <string>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int map[34];
int score[34];
int turn[34];
bool check[34];
int position[4];
int dice[10];

int Max = 0;

void init() {
	//다이스 받기
	for (int i = 0; i < 10; i++) {
		int tmp = 0;
		cin >> tmp;
		dice[i] = tmp;
	}
	//바깥쪽 설정 인덱스 0번에 다음에 갈 1번이저장되어있음
	for (int i = 0; i < 21; i++) {
		map[i] = i+1;
	}

	//도착점
	map[21] = 21;

	for (int i = 22; i < 27; i++) {
		map[i] = i + 1;
	}
	map[27] = 20;

	map[28] = 29; map[29] = 30; map[30] = 25;
	map[31] = 32; map[32] = 25;

	//10 20 30에서 파랑색 방향
	turn[5] = 22;
	turn[10] = 31;
	turn[15] = 28;

	//점수판 갱신
	for (int i = 0; i < 21; i++) {
		score[i] = i * 2;
	}
	score[22] = 13; score[23] = 16; score[24] = 19;
	score[25] = 25; score[26] = 30; score[27] = 35;
	score[28] = 28; score[29] = 27; score[30] = 26;
	score[31] = 22; score[32] = 24;
}

void dfs(int cnt, int num) {
	if (cnt == 10) {
		if (num > Max)Max = num;
		return;
	}

	//4개의 말 확인
	for (int i = 0; i < 4; i++) {
		int move = dice[cnt];
		int current_pos = position[i];
		int next_pos = current_pos;
		//어차피 주사위는 한번은 굴림 파랑색에서 출발시 한칸 먼저 움직이기
		if (turn[current_pos] > 0) {
			move--;
			next_pos = turn[current_pos];
		}

		//움직이기
		while (move > 0) {
			move--;
			next_pos = map[next_pos];
		}

		if (next_pos == 21 || !check[next_pos]) {
			//cout << next_pos << " ";
			position[i]=next_pos;
			check[current_pos] = false;
			check[next_pos] = true;

			dfs(cnt + 1, num + score[next_pos]);

			position[i]=current_pos;
			check[current_pos] = true;
			check[next_pos] = false;
		}
	}
	
}

int main() {
	init();
	dfs(0,0);
	cout << Max;
}