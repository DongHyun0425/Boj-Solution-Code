#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
using namespace std;

int N = 0;
int M = 0;
int Answer = 0;
vector<int> c;
vector<int> box;

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp = 0;
		cin >> tmp;
		c.push_back(tmp);
	}
	sort(c.begin(), c.end(), greater<>());

	cin >> M;
	for (int i = 0; i < M; i++) {
		int tmp = 0;
		cin >> tmp;
		box.push_back(tmp);
	}
	sort(box.begin(), box.end(), greater<>());

}

void solve() {
	if (box[0] > c[0]) {
		cout << "-1";
		return;
	}else {
		while (box.size() > 0) {
			for (int i = 0; i < c.size(); i++) {
				int idx = lower_bound(box.begin(), box.end(), c[i], greater<>()) - box.begin();
				if(box.size()>0 && idx<= box.size()-1) box.erase(box.begin() + idx); //
			}
			Answer++;
		}
		cout << Answer;
		return;
	}
}

int main() {
	init();
	solve();
}