#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

int N = 0;
vector<int> v;
int map[402][402];
vector<int> arr[402];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

struct Node{
	int Love;
	int Empty;
	int i;
	int j;
	int num;

	Node(int l, int e, int i, int j,int n) {
		this->Love = l;
		this->Empty = e;
		this->i = i;
		this->j = j;
		this->num = n;
	}
};

bool love(int x, int y) {
	for (int i = 0; i < 4; i++) {
		if (map[x][y] == v[i]) return true;
	}
	return false;
}

bool comp(const Node& a, const Node& b) {
	if (a.Love != b.Love)return a.Love > b.Love;
	if (a.Empty != b.Empty)return a.Empty > b.Empty;
	if (a.i != b.i)return a.i < b.i;
	return a.j < b.j;
}

void solve() {
	cin >> N;
	for (int a = 0; a < N * N; a++) {
		v.clear();
		int num = 0;
		cin >> num;

		for (int i = 0; i < 4; i++) {
			int tmp = 0;
			cin >> tmp;
			v.push_back(tmp);
			arr[num].push_back(tmp);
		}

		vector<Node> NODE;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 0) {
					int L = 0;
					int Empty = 0;
					for (int b = 0; b < 4; b++) {
						int nx = i + dx[b];
						int ny = j + dy[b];
						if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
							if (love(nx, ny))L++;
							if (map[nx][ny] == 0) Empty++;
						}
					}
					NODE.push_back(Node(L, Empty, i, j,num));
				}
			}
		}
		sort(NODE.begin(), NODE.end(),comp);

		Node n = NODE[0];
		map[n.i][n.j] = n.num;
	}

	//점수계산
	int Answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp = 0;
			for (int b = 0; b < 4; b++) {
				int nx = i + dx[b];
				int ny = j + dy[b];
				if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
					for (int a = 0; a < 4; a++) {
						if (map[nx][ny] == arr[map[i][j]][a])tmp++;
					}
				}
			}
			if (tmp == 1)Answer += 1;
			if (tmp == 2)Answer += 10;
			if (tmp == 3)Answer += 100;
			if (tmp == 4)Answer += 1000;
		}
	}
	cout << Answer;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}