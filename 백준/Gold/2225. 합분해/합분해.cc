#include <iostream>

using namespace std;

long long DP[201][201];

int main() {
	int N = 0;
	int K = 0;
	cin >> N >> K;

	for (int i = 0; i <= N; i++) {
		DP[1][i] = 1;
	}

	//2개를 가지고
	for (int k = 2; k <= K; k++) {
		//0을만드는법,1을 만드는법,,,N을 만드는법
		for (int n = 0; n <= N; n++) {
			//DP[3][3] = DP[2][0] + DP[2][1]... DP[2][3];
			for (int i = 0; i <= n; i++) {
				DP[k][n] += DP[k - 1][i];
			}
			DP[k][n] = DP[k][n] % 1000000000;
		}
	}

	cout << DP[K][N] << "\n";
	return 0;
}