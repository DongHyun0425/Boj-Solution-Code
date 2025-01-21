#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
int Answer = 0;

void make(int x, int y, int d, int g) {
	vector<int> v;
	v.push_back(d);
	for (int i = 0; i < g; i++) {
		for (int j = v.size() - 1; j >= 0; j--) {
			int t = (v[j] + 1) % 4;
			v.push_back(t);
		}
	}
	map[y][x] = 1;
	for (int i = 0; i < v.size(); i++) {
		int nx = x + dx[v[i]];
		int ny = y + dy[v[i]];
		map[ny][nx] = 1;
		x = nx;
		y = ny;
	}

}


int main() {
	int T = 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		make(x, y,d, g);
	}
	for (int i = 0; i <= 99; i++) {
		for (int j = 0; j <= 99; j++) {
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1]) {
				Answer++;
			}
		}
	}
	cout << Answer;
	return 0;
}