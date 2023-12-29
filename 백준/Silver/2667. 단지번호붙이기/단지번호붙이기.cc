#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool visited[25][25];
int map[25][25];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

queue<pair<int, int>>q;
vector <int>v;
int total;

void bfs(int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && !visited[i][j]) {
                total+=1;
				int count = 1;
				visited[i][j] = true;
				q.push({ i,j });
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (map[nx][ny] == 1 && !visited[nx][ny] && nx >= 0 && ny >= 0 && nx < N && ny < N) {
							visited[nx][ny] = true;
							q.push({ nx,ny });
							count++;
						}
					}
				}	
				v.push_back(count);	
			}
		}
	}
    cout<<total<<"\n";
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}

int main() {
	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string k;
		cin >> k;
		for (int j = 0; j < N; j++) {
			map[i][j] = k[j] - '0';
		}
	}
	bfs(N);
}