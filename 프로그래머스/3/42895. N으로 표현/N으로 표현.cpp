#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set> 
using namespace std;

int getdouble(int i, int N) {
    int temp = 0;
    for (int j = 0; j < i; j++) {
        temp += N * pow(10, j);
    }
    return temp;
}

int solution(int N, int number) {
    
vector<unordered_set<int>> Dp(9);
    Dp[0].insert(0);
        Dp[1].insert(N);
   
     if (N == number) return 1;
    for (int i = 2; i < 9; i++) {
        Dp[i].insert(getdouble(i, N));
        for (int x = 1; x <= i; x++) {
            for (int y = 1; y <= i; y++) {
                if (x + y == i) {
                    for (int a : Dp[x]) {
                        for (int b : Dp[y]) {
                            Dp[i].insert(a+b);
                            if(a-b>0) Dp[i].insert(a-b);
                            Dp[i].insert(a*b);
                            if(a/b>0) Dp[i].insert(a/b);
                        }
                    }
                
                }
            }
        }
        if (Dp[i].find(number)!=Dp[i].end()) {
            return i;
        }
    }
    return -1;
}