#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

string map[5][5];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
vector<string> v;
void dfs(int x, int y, int count, string a) {
	if (count == 5) {
		if (find(v.begin(), v.end(), a) == v.end()) {
			v.push_back(a);
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			   int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx <= 4 && ny >= 0 && ny <= 4) {
					string b = a + map[nx][ny];
					dfs(nx, ny, count+1, b);
				}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			string a = "";
			cin >> a;
			map[i][j] = a;
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i, j, 0, map[i][j]);
		}
	}

	cout << v.size();
}