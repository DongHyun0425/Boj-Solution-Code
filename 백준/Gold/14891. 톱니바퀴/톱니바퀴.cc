#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

deque<int>q[5];
bool visited[5];
void init() {
	for (int i = 1; i <= 4; i++) {
		string s = "";
		cin >> s;
		for (int j = 0; j < 8; j++) {
			q[i].push_back(s[j]-'0');
		}
	}
}

void move(int idx, int direction) {
	//반시계방향인경우
	if (direction == -1) {
		int temp = q[idx].front();
		q[idx].pop_front();
		q[idx].push_back(temp);
	}
	else {
		//시계인경우
		int temp = q[idx].back();
		q[idx].pop_back();
		q[idx].push_front(temp);
	}
}

void rotate(int idx, int direct) {
	visited[idx] = true;
	//회전시킬 방향의 오른쪽,왼쪽의 극
	int right = q[idx][2];
	int left = q[idx][6];

	move(idx, direct); //일단 자기 자신 회전

	//이제 양 옆 확인
	//오른쪽 확인,극이 달라야함
	if (idx + 1 <= 4 && right != q[idx + 1][6] && !visited[idx+1]) {
		if (direct == 1) rotate(idx + 1, -1);
		else rotate(idx + 1, 1);
	}

	//왼쪽 확인, 극이달라야함
	if(idx-1>=1 && left != q[idx-1][2] && !visited[idx-1]){
		if (direct == 1) rotate(idx - 1, -1);
		else rotate(idx - 1, 1);
	}
}

void solve() {
	int K = 0;
	cin >> K;
	while (K > 0) {
		K--;
		int idx = 0;
		int direct = 0;
		cin >> idx >> direct;
		memset(visited, false, sizeof(visited));

		//번호랑, 방향가지고 rotate호출
		rotate(idx, direct);
	}

	int Answer = 0;
	//점수확인
	if (q[1][0] == 1) Answer += 1;
	if (q[2][0] == 1)Answer += 2;
	if (q[3][0] == 1) Answer += 4;
	if (q[4][0] == 1)Answer += 8;

	cout << Answer;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	init();
	solve();
}