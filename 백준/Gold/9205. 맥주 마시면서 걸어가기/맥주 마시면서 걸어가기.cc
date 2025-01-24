#include <vector>
#include <iostream>
#include <queue>
#include <string.h>
#include <cmath>
#include <string>
using namespace std;
int T;

vector<pair<int, int>>g;
bool visited[150];
string answer = "sad";

void BFS(int hx, int hy, int px, int py) {
	queue<pair<int,int>>q;
	q.push({ hx,hy });
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;

		q.pop();

		int walk = abs(px - cx) + abs(py - cy);
		if (walk <= 1000) {
			answer = "happy";
			return;
		}

		for (int t = 0; t < g.size();t++) {
			//현재위치에서 편의점까지 갈 수 있는가?
			if (!visited[t]) {
				int walk = abs(g[t].first - cx) + abs(g[t].second - cy);
				if (walk <= 1000) {
					visited[t] = true;
					q.push({ g[t].first,g[t].second });
				}
			}
		}
	}
}

int main(){
	cin >> T;
	for (int i = 0; i < T; i++) {
		int hx, hy, n, px, py;
		cin >> n;
		cin >> hx >> hy;
		for (int j = 0; j < n; j++) {
			int gx, gy;
			cin >> gx >> gy;
			g.push_back({ gx,gy });
		}
		cin >> px >> py;

		BFS(hx, hy, px, py);
		cout << answer << "\n";
		answer = "sad";
		//visited초기화
		memset(visited, false, sizeof(bool) * 150);
		//g초기화
		g.clear();
	}
}
