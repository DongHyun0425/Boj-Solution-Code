#include <string>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N = 0;
int M = 0;
int Answer = 0;

vector<int> party[51];
bool true_lie[51];
int parent[51];
vector <int> person;

void init() {
	for (int i = 0; i < 51; i++) {
		parent[i] = i;
	}

	cin >> N >> M;
	
	//step 1: 진실 아는 사람 저장
	int temp = 0;
	cin >> temp;
	for (int i = 0; i < temp; i++) {
		int t = 0;
		cin >> t;
		person.push_back(t);
	}
}

int find_parent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find_parent(parent[x]);
}

void merge(int a, int b) {
	int x = find_parent(a);
	int y = find_parent(b);

	if (x < y) { 
		parent[y] = x;
	}else{
		parent[x] = y;
	}
}

void solve() {
	//step 2: 파티 순회하면서 parent랑 merge
	for (int i = 0; i < M; i++) {
		int temp = 0;
		cin >> temp;

		int before = 0;

		//1 2 3 4 
		for (int j = 0; j < temp; j++) {
			int t = 0;
			cin >> t;

			party[i].push_back(t);

			if (j == 0) {
				before = t;
			}
			else {
				merge(before, t);
				before = t;
			}
		}
	}
    
    //전부갱신
    for(int i=1;i<=N;i++) find_parent(i);

	//step 3: parent만큼 파티 순회해서 true 갱신
	for (int i = 0; i < person.size(); i++) {
		int tnum = person[i];
		int p = parent[tnum];

		for (int i = 1; i <= N; i++) {
			if (parent[i] == p) true_lie[i] = true;
		}
	}

	//step 4: 지금 현재 진실아는사람 true, 거짓 false party 돌기
	for (int i = 0; i < M; i++) {
		bool flag = false;
		for (int j = 0; j < party[i].size(); j++) {
			if (true_lie[party[i][j]]) {
				flag = true;
				break;
			}
		}
		if (!flag) Answer++;
	}
	
	cout << Answer;
}

int main() {
	init();
	solve();
}