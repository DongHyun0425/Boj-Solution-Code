#include <string>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N = 0;
int M = 0;
int byte1[101] = { 0, };
int cost[101] = { 0, };
int dp[100001] = { 0, };

int main() {
	//변수 초기화
	cin >> N;
	cin >> M;
	for (int i = 0; i < N; i++) {
		cin >> byte1[i + 1];
	}
	for (int i = 0; i < N; i++) {
		cin >> cost[i + 1];
	}

	//30, 3부터 확인
	for (int i = 1; i <= N; i++) {
		int Byte = byte1[i];
		int Cost = cost[i];

		for (int j = 10000; j >= 0; j--) {
			//그래야 DP[j-COST]에서 outofBOund안생김
			if (j >= Cost) {
				int comp_cost = dp[j - Cost];
				if (comp_cost + Byte > dp[j])dp[j] = comp_cost + Byte;
			}
		}
	}

	int answer = 0;

	for (int i = 0; i <= 10000; i++) {
		if (dp[i] >= M) {
			answer = i;
			break;
		}
	}
	cout << answer;
	return 0;
}