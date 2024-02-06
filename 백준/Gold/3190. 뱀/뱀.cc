#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <iostream>
#include <algorithm>
using namespace std;

int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };
deque<pair<int, int>>dq;
queue<pair<int, char>> mh;
int map[101][101] = { 0, };
bool check[101][101] = { false, };

int main() {
	int n = 0;
	cin >> n;
	int k = 0;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int x = 0;
		int y = 0;
		cin >> x >> y;
		map[x][y] = 1;
	}

	int l = 0;
	cin >> l;
	for (int i = 0; i < l; i++) {
		int temp = 0;
		char t;
		cin >> temp >> t;
		mh.push({ temp,t });
	}

	int cx = 1;
	int cy = 1;
	int chp = 0;
	int time = 0;
	dq.push_front({ 1,1 });
	check[1][1] = true;

	while (1) {
		time++;
		int nx = cx + dx[chp];
		int ny = cy + dy[chp];
		if (nx > n || ny > n || nx < 1 || ny < 1 || check[nx][ny] == true) {
			break;
		}

		cx = nx;
		cy = ny;
		dq.push_front({ cx,cy });
		check[cx][cy] = true;

		if (map[cx][cy] == 0) {
			int tx = dq.back().first;
			int ty = dq.back().second;
			check[tx][ty] = false;
			dq.pop_back();
		}
		else {
			map[cx][cy] = 0;
		}

		if (!mh.empty()&&time == mh.front().first) {
			if (mh.front().second == 'D') {
				chp = (chp + 3) % 4;
				mh.pop();
			}
			else {
				chp = (chp + 1) % 4;
				mh.pop();
			}
		}
	}
	cout << time;
}