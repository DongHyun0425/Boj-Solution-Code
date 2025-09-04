#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N = 0;
int M = 0;
int K = 0;
int Answer = 0;

int soil[11][11];
int add[11][11];
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
vector<int> tree[11][11];
vector<pair<int, pair<int, int>>> dead;


void init(){
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			soil[i][j] = 5;
			cin >> add[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		int x, y, age;
		cin >> x >> y >> age;
		tree[x][y].push_back(age);
	}
}

void spring() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			vector<int> v = tree[i][j];
			vector<int> temp; //나무 정보 저장
			sort(v.begin(), v.end()); // 나이가 어린 나이순 부터 영양섭취
			

			for (int a = 0; a < v.size(); a++) {
				if (soil[i][j] >= v[a]) {
					temp.push_back(v[a] + 1);//나이 한살 추가
					soil[i][j] -= v[a];//땅 영양 감소
				}
				else {
					//죽은나무저장
					dead.push_back({ v[a],{i,j} });
				}
			}


			//나무정보 갱신
			tree[i][j].clear();
			tree[i][j] = temp;
		}
	}
}

void summer() {
	for (int i = 0; i < dead.size(); i++) {
		int age = dead[i].first;
		int x = dead[i].second.first;
		int y = dead[i].second.second;

		soil[x][y] += age / 2;
	}
}

void fall() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			vector<int> v = tree[i][j];
			for (int a = 0; a < v.size(); a++) {
				//나이가 5의 배수이면
				if (v[a] % 5 == 0) {
					//map 밖으로 나가면 안됨
					for (int d = 0; d < 8; d++) {
						int nx = i + dx[d];
						int ny = j + dy[d];
						if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
							tree[nx][ny].push_back(1);
						}
					}
				}
			}
		}
	}
}

void winter() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			soil[i][j] += add[i][j];
		}
	}
}

void solve() {
	while (K > 0) {
		K--;
		dead.clear();//죽은나무 갱신

		//step 1: spring
		spring();

		//step 2: summer
		summer();

		//step 3: fall
		fall();

		//step 4: winter
		winter();
	}

	//step 5: 산나무 체크
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			Answer += tree[i][j].size();
		}
	}

	cout << Answer;
}

int main() {
	init();
	solve();
}