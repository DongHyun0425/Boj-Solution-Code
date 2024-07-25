#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	int K = 0;
	string n = "";

	cin >> N;
	cin >> K;
	cin >> n;

	stack<char>c;

	for (int i = 0; i < n.size(); i++) {
		char f = n[i];
		while (c.size() > 0 && c.top() - '0' < f - '0' && K > 0) {
			c.pop();
			K--;
		}
		c.push(f);
	}

	for (int i = 0; i < K; i++) {
		c.pop();
	}

	stack<char>tt;

	while (c.size() > 0) {
		tt.push(c.top());
		c.pop();
	}

	while (tt.size() > 0) {
		cout << tt.top();
		tt.pop();
	}
	return 0;
}