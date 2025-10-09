#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

void fn() {
    string s = "";
    cin >> s;
    stack<char> left;
    stack<char> right;

    for (int i = 0; i < s.size(); i++) {
        int c = s[i];

        //<인경우
        if (c == '<') {
            if (!left.empty()) {
                right.push(left.top());
                left.pop();
            }
            else continue;
        }
        //>인경우
        else if (c == '>') {
            if (!right.empty()) {
                left.push(right.top());
                right.pop();
            }
            else continue;
        }
        //-인경우
        else if (c == '-') {
            if (!left.empty()) {
                left.pop();
            }
            else continue;
        }
        else {
            //문자인경우
            left.push(c);
        }
    }

    //꺼꾸로 출력
    stack<char>stack1;

    while (!left.empty()) {
        stack1.push(left.top());
        left.pop();
    }

    while (!stack1.empty()) {
        cout << stack1.top();
        stack1.pop();
    }

    while (!right.empty()) {
        cout << right.top();
        right.pop();
    }
    cout << "\n";
}

void solve() {
    int T = 0;
    cin >> T;
    for (int i = 0; i < T; i++) {
        fn();
    }
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
    solve();
    return 0;
}