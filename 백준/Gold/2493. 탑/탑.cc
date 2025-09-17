#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void solve() {
	int N = 0;
	cin >> N;

	stack<pair<int, int>>s;

	for (int i = 1; i <= N; i++) {
		int length = 0;
		cin >> length;
		bool flag = false;
		int temp = 0;
		while (!s.empty()) {
			int L = s.top().first;
			int idx = s.top().second;

			if (length > L) {
				s.pop();
			}
			else {
				flag = true;
				temp = idx;
				break;
			}
		}

		s.push({ length,i });
		if (flag) {
			cout << temp << " ";
		}
		else {
			cout << "0 ";
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}