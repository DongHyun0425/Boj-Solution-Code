#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n = 0;
int x = 0;
int Answer = 0;
bool Need[2000001];
vector<int>v;

void init() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp = 0;
		cin >> temp;
		v.push_back(temp);
	}
	cin >> x;
}

void solve() {
	for (int i = 0; i < n; i++) {
		//1번 내가 필요한 숫자인가?
		if (Need[v[i]]) {
			Answer++;
		}
		//2번 그럼 내가 필요한 숫자는 무엇인가?
		if (x - v[i] >= 0) {
			Need[x - v[i]] = true;
		}
	}
}

int main() {
	init();
	solve();
	cout << Answer;
}