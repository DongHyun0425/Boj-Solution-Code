#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

string s = "";
string bomb = "";

void init() {
	cin >> s >> bomb;
}

void solve() {
	stack<pair<char,int>>stk;
	for (int i = 0; i < s.size(); i++) {
		char c = s[i];

		//step 1: stack이 비워져있는경우
		if (stk.empty()) {
			if (bomb[0] == c) {
				stk.push({ c,1 });
				if (bomb.size() == 1) stk.pop();
			}
			else {
				stk.push({ c,0 });
			}
		}
		else {
			//step 2: stack에 뭐라도 있는경우
			char t = stk.top().first;
			int n = stk.top().second;

			//다음에 올 문자열이 맞는경우
			if (bomb[n] == c) {
				stk.push({ c,n + 1 });
				//만약 이게 size가 동일한경우
				if (n + 1 == bomb.size()) {
					for (int i = 0; i < bomb.size(); i++) {
						stk.pop();
					}
				}
			}
			else {
				//다음에 올 문자열이 아닌 경우
				if (bomb[0] == c) {
					stk.push({ c,1 });
				}
				else {
					stk.push({ c,0 });
				}
			}
		}
	}

	
	if (stk.empty()) {
		cout << "FRULA";
	}
	else {
		stack<char> temp;
		while (!stk.empty()) {
			temp.push(stk.top().first);
			stk.pop();
		}

		string t = "";
		while (!temp.empty()) {
			t+=temp.top();
			temp.pop();
		}
		cout << t;
	}
}

int main() {
	init();
	solve();
}