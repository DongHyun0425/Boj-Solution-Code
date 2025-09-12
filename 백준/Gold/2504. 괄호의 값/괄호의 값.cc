#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

struct Temp {
	char c;
	int n;

	Temp(char a, int b) {
		this->c = a;
		this->n = b;
	}
};

string str = "";

bool flag = false;

stack<Temp>s;
void solve() {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') s.push(Temp('(', 0));
		if (str[i] == '[') s.push(Temp('[', 0));
	
		if (str[i] == ')') {
			int temp = 0;
			bool ff = false;
			while (!s.empty()) {
				Temp t = s.top();
				s.pop();
				char c = t.c;
				int n = t.n;

				if (c == '[' || c == ']') {
					flag = true;
					return;
				}

				if (n > 0) temp += n;
				if (c == '(') {
					ff = true;
					if (temp == 0) {
						temp += 2;
						s.push(Temp(' ',temp ));
						break;
					}
					else {
						temp *= 2;
						s.push(Temp(' ', temp));
						break;
					}
				}
			}
			if (!ff) flag = true;
		}
		
		if (str[i] == ']') {
			int temp = 0;
			bool ff = false;
			while (!s.empty()) {
				Temp t = s.top();
				s.pop();
				char c = t.c;
				int n = t.n;

				if (c == '(' || c == ')') {
					flag = true;
					return;
				}

				if (n > 0) temp += n;
				if (c == '[') {
					ff = true;
					if (temp == 0) {
						temp += 3;
						s.push(Temp(' ', temp));
						break;
					}
					else {
						temp *= 3;
						s.push(Temp(' ', temp));
						break;
					}
				}
			}
			if (!ff) flag = true;
		}
	}
}

int main() {
	cin >> str;
	solve();
	int Answer = 0;
	while (!s.empty()) {
		Answer += s.top().n;
		if (s.top().c == '(' || s.top().c == ')' || s.top().c == '[' || s.top().c == ']') flag = true;
		s.pop();
	}
	if (flag) { cout << "0"; }
	else {
		cout << Answer;
	}
}

//(([[]()()]))