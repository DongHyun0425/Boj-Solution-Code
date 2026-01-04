#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

int N = 0;
int before = -1;
int Answer = 0;
vector <pair<long, long>>v;

void init();
void solve();

void init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        long a = 0;
        long b = 0;
        cin >> a >> b;
        v.push_back({a,b});
    }
}

bool comp(const pair<long, long>& a,const pair<long, long>& b) {
    if (a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}

void solve() {
    sort(v.begin(), v.end(), comp);

    //v돌면서 확인
    for (int i = 0; i < v.size(); i++) {
        if (v[i].first>=before) {
            Answer++;
            before = v[i].second;
        }
    }
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
    init();
    solve();
    
    cout << Answer;

    return 0;
}