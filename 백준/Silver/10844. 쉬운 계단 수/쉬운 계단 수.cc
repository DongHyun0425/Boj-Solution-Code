#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable : 4996)
#define Moduler 1000000000
using namespace std;
//두번째가 끝자리의 숫자 x1,xx2이런식
long long dp[101][10];

int main() {
	int n = 0;
	cin >> n;
	long long answer=0;
	//자리수가 1인놈들 전부 1로 초기화 왜냐면 1 2 3... 한가지 밖에 없으니까
	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1;
	}
	//0으로는 시작 못하니까 0으로 초기화
	dp[1][0] = 0;
	
	for (int i = 2; i < n+1; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) { dp[i][j] = dp[i - 1][j + 1]% Moduler; }
			else if (j == 9) { dp[i][j] = dp[i - 1][j - 1] % Moduler; }
			else { dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % Moduler; }
		}
	}

	for (int i = 0; i < 10; i++) {
		answer += dp[n][i];
	}

	cout << answer % Moduler;
}