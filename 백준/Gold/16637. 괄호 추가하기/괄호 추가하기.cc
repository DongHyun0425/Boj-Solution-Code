#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

int num = 0;
int Answer = -99999999;
int k = 0;
vector<char> o;
vector<int> arr;

void init() {
    cin >> k;

    for (int i = 0; i < k; i++) {
        if (i % 2 == 0) {
            int tmp = 0;
            cin >> tmp;
            arr.push_back(tmp);
        }
        else {
            char c = ' ';
            cin >> c;
            o.push_back(c);
        }
    }

    num = k / 2;
}

vector<bool>v;
vector<vector<bool>>r;

void fn(bool use) {
    if (v.size() == num) {
        r.push_back(v);
        return;
    }

    if (!use) {
        v.push_back(true);
        fn(true);
        v.pop_back();
    }

    v.push_back(false);
    fn(false);
    v.pop_back();
}

int op(int a, int b,char c) {
    if (c == '+') return a + b;
    if (c == '-') return a - b;
    return a * b;
}

void cal() {
    ///r[0] 0 0 1
    for (int i = 0; i < r.size(); i++) {
        vector<bool>v = r[i];
        stack<int>st;
        st.push(arr[0]);
        for (int j = 0; j < o.size(); j++) {
            //오퍼레이터 참이면 묶어야함
            if (v[j]) {
               int n = op(st.top(),arr[j+1],o[j]);
               st.pop();
                st.push(n);
            }else {
                st.push(o[j]);
                st.push(arr[j+1]);
             }
         }

        stack<int> tmp;
        while (!st.empty()) {
            tmp.push(st.top());
            st.pop();
        }

        int tt = tmp.top();
        tmp.pop();
        //오퍼레이팅 뒤에 더있다면
        while (!tmp.empty()) {
            char c = ' ';
            int tttt = tmp.top();
            if (tttt == 43) c = '+';
            if (tttt == 42) c = '*';
            if (tttt == 45) c = '-';
            tmp.pop();

            int ttt = tmp.top();
            tmp.pop();
            
            tt = op(tt, ttt, c);
        }
        if (Answer < tt) Answer = tt;
    }
}

void solve() {
    fn(false);
    cal();
    /*for (int i = 0; i < r.size(); i++) {
        for (int j = 0; j < r[i].size(); j++) {
            cout << r[i][j] << " ";
        }
        cout << "\n";
    }*/
    cout << Answer;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
    init();
    solve();
    return 0;
}