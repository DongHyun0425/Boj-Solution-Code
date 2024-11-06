#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N = 0;
int M = 0;
vector<int> map[2001];
bool visited[2001];
int correct = 0;

void BT(int temp, int depth) {
	if (depth == 4) {
		correct = 1;
		return;
	}
	visited[temp] = true;

	for (int i = 0; i < map[temp].size(); i++) {
		if (!visited[map[temp][i]]) {
			BT(map[temp][i], depth + 1);
			visited[map[temp][i]] = false;
		}
	}
}
int main() {
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int t1 = 0;
		int t2 = 0;
		cin >> t1 >> t2;
		map[t1].push_back(t2);
		map[t2].push_back(t1);
	}
	for (int i = 0; i < N; i++) {
		BT(i, 0);
		visited[i] = false;
		if (correct) { cout << "1";  break; }
	}
	if(!correct){
		cout << "0";
	}
	return 0;
}