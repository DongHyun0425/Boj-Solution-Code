#include <algorithm>
#include <string>
#include <stack>
#include <iostream>
using namespace std;
using namespace std;

string s, bomb;

void solve() {
    stack<pair<char, int>> stk;

    for (char c : s) {
        int matched = 0;
        if (!stk.empty() && bomb[stk.top().second] == c) {
            matched = stk.top().second + 1; // 이전 매칭 길이 + 1
        } else if (bomb[0] == c) {
            matched = 1; // 새로운 매칭 시작
        }
        stk.push({c, matched});

        if (matched == bomb.size()) {
            // 폭발 문자열과 일치하면 pop
            for (int i = 0; i < bomb.size(); i++) stk.pop();
        }
    }

    if (stk.empty()) {
        cout << "FRULA";
    } else {
        string result;
        while (!stk.empty()) {
            result += stk.top().first;
            stk.pop();
        }
        reverse(result.begin(), result.end());
        cout << result;
    }
}

int main() {
    cin >> s >> bomb;
    solve();
}