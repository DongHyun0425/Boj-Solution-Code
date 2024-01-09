#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
#include <tuple>

using namespace std;
 int map[201] = { 0 };
  int N, M = 0;
 int ffind(int x) {
     if (map[x] == x) { return x; }

     return map[x]=ffind(map[x]);
 }

void merge(int N, int a) {
    int x = ffind(N);
    int y = ffind(a);

    if (x == y) {
        return;
    }
    else if(x > y){
        map[x] = y;
    }
    else 
    {
        map[y] = x;
    }
}
int cnt = 0;
void result() {
    vector<int >v;
    for (int i = 0; i < M; i++) {
        int k = 0;
        cin >> k;
        v.push_back(k);
    }

    for (int i = 0; i < M-1; i++) {
        if (ffind(v[i]) == ffind(v[i+1])) {
            continue;
        }
        else {
            cout << "NO";
            cnt++;
            return;
        }
    }
 }


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
  
    cin >> N >> M;
   
    
    for (int i = 1; i < 200; i++) {
        map[i] = i;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int a = 0;
            cin >> a;
            if (a == 1) {
                merge(i, j);
            }
        }
    }
   
    result();

    if (cnt == 0) {
        cout << "YES";
    }
    return 0;
}