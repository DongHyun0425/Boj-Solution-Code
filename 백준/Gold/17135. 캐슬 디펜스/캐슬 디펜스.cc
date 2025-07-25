#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//N*M
// 격자판에는 성이있다.
// 3명의 궁수, 궁수가 동시에 적을 공격
// D이하인 적중에 가장 가까운적, 그게 여러신경우 가장 왼쪽의 적
// 같은적이 여러 궁수한테 공격당할수 있따.
//공격받으면 제외된다. 
// 궁수의 공격이 끝나면 적이 아래로 한칸이동, 성이 있는 칸으로 이동하면 게임에서 제외
// 15C3은 5 7 13 * for문 3개 * 225 * 15 왜 꼭 bfs를 써야하지?

// 1. init으로 맵 받기
// 2. 궁수를 순열로 배치하기, 배치후 궁수의 포지션에 좌표 넣기
// 3. get_적의 위치에다가 for문으로 호출 그리고 get_적에서 궁수 포지션으로 bfs
// bfs할때 왼 위 오로 탐색하며 1이면 바로 return으로 좌표 반환 방문처리하면 안됨
// 4. for문으로 적의 위치를 파악했으면, map좌표에 -1하고 if그 좌표가 0이면 +1
// -1하고 좌표가 음수값이면 정답 +1안함
// 5. 그다음에 궁수위치 조정 궁수의 위치가 N값이 -1로 가야함
typedef struct {
	int x;
	int y;
	int Dist;
}Enemy_Info;

int MAP[16][16];
int CopyMap[16][16];
int N, M, D;
int Select[16];
vector<int> Pos;
int candi_Answer;
int Answer;
vector<pair<int, int>> V;

void init() {
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int tmp = 0;
			cin >> tmp;
			MAP[i][j] = tmp;
		}
	}
}

void Copy_Map() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			CopyMap[i][j] = MAP[i][j];
		}
	}
}

bool All_Kill() {
	bool flag = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (CopyMap[i][j] == 1) {
				//해당 Map에서 적들을 전부 넣어줌
				V.push_back({ i,j });
				flag = false;
			}
		}
	}
	return flag;
}
/*
bool Standard(Enemy_Info A, Enemy_Info B) {
	if (A.Dist <= B.Dist) {
		if (A.Dist == B.Dist) {
			if (A.y < B.y) {
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}
*/
bool Standard(Enemy_Info A, Enemy_Info B) {
	if (A.Dist == B.Dist) {
		return A.y < B.y;
	}
	return A.Dist < B.Dist;
}
void Shot() {
	//현재 V에는 CopyMap에 있는 모든 적들이 들어있고
	//Pos에는 궁수의 위치가 들어있음
	//그러면 궁수 3개를 돌면서 가장 가까운 적을 먼저 찾아야함
	//죽일 최종 좌표
	pair<int, int> kill[3];
	bool visited[16][16] = {false,};
	for (int i = 0; i < 3; i++) {
		vector<Enemy_Info> enemy_temp;

		//궁수 좌표
		int archor_xpos = N;
		int archor_ypos = Pos[i];

		for (int a = 0; a < V.size(); a++) {
			int e_xpos = V[a].first;
			int e_ypos = V[a].second;
			int Distance = abs(archor_xpos - e_xpos) + abs(archor_ypos - e_ypos);
			//궁수와 거리를 저장해서 앞으로 죽일 Vector에다가 넣어두기
			if (Distance <= D) {
				Enemy_Info Temp;
				Temp.x = e_xpos;
				Temp.y = e_ypos;
				Temp.Dist = Distance;
				enemy_temp.push_back(Temp);
			}
		}

		if (enemy_temp.size() > 1) {
			sort(enemy_temp.begin(), enemy_temp.end(), Standard);
			kill[i].first = enemy_temp[0].x;
			kill[i].second = enemy_temp[0].y;
		}
		else if (enemy_temp.size() == 1) {
			kill[i].first = enemy_temp[0].x;
			kill[i].second = enemy_temp[0].y;
		}
		else {
			kill[i].first = -1;
			kill[i].second = -1;
		}

	}

	//최종적으로 죽일 좌표가 kill배열에 들어감
	//1. copy map을 0으로 만들기
	for (int i = 0; i < 3; i++) {
		int x = kill[i].first;
		int y = kill[i].second;
		if (x == -1)continue;
		CopyMap[x][y] = 0;
		//2. visited를 통해 false라면 Temp_Answer++
		if (!visited[x][y]) candi_Answer++;
		visited[x][y] = true;
	}
}

void Move_Enemy() {
	for (int i = V.size() - 1; i >= 0; i--) {
		int x = V[i].first;
		int y = V[i].second;

		if (CopyMap[x][y] == 0) continue;
		if (x == N - 1) {
			CopyMap[x][y] = 0;
		}
		else {
			CopyMap[x + 1][y] = 1;
			CopyMap[x][y] = 0;
		}
	}
}

void Kill_The_Enemy() {
	//map을 전부 돌면서 적을 확인 일단 copy map
	Copy_Map();
	while (1) {
		V.clear();
		//언제까지 할꺼냐?
		if (All_Kill() == true) break;
		Shot();
		Move_Enemy();
	}

}

void archor_pos(int pos,int cnt) {
	//2번 궁수의 좌표 구하기
	if (cnt == 3) {
		//궁수의 좌표를 구했다면, 적을 죽이기
		candi_Answer = 0;
		Kill_The_Enemy();
		if (candi_Answer > Answer) Answer = candi_Answer;
		return;
	}

	for (int i = pos; i < M; i++) {
		if (!Select[i]) {
			Select[i] = true;
			Pos.push_back(i);
			archor_pos(pos, cnt + 1);
			Select[i] = false;
			Pos.pop_back();
		}
	}
}

int main() {
	//1번
	init();
	archor_pos(0,0);
	cout << Answer;
}