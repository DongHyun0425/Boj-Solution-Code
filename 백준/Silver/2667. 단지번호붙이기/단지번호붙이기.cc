#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int map[25][25];
queue<pair<int, int>>q;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
vector <int > v;
void bfs(int a) {
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			int count = 1;
			if (map[i][j] == 1) {
				map[i][j] = 2;
				q.push({ i, j });
				while (!q.empty()) {
					int x = q.front().second;
					int y = q.front().first;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (map[ny][nx] == 1 && nx >= 0 && ny >= 0 && nx < a && ny < a) {
							map[ny][nx] = map[y][x] + 1;
							q.push({ ny,nx });
							count++;
						}
					}
				}
				v.push_back(count);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}

int main() {
	int a;
	cin >> a;
	for (int i = 0; i < a; i++) {
		string k;
		cin >> k;
		for (int j = 0; j < a; j++) {
			map[i][j] = k[j] - '0';
		}
	}
	bfs(a);
}