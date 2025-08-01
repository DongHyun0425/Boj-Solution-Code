#include <string>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N = 0;
int M = 0;

int arr[2001] = { 0, };
bool dp[2001][2001] = { false, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int tmp = 0;
		cin >> tmp;
		arr[i] = tmp;
	}

	//길이가 1인 팬린드롬
	for (int i = 1; i <= N; i++) {
		dp[i][i] = true;
	}

	//길이가 2인 팬린드롬
	for (int i = 1; i <= N-1; i++) {
		if (arr[i] == arr[i + 1]) dp[i][i + 1] = true;
	}

	//길이가 3이상인 팬린드롬
	for (int i = N-2; i >= 1; i--) {
		for (int j = i+2; j <= N; j++) {
			if (arr[i] == arr[j] && dp[i+1][j - 1]) dp[i][j] = true;
		}
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b = 0;
		cin >> a >> b;
		if (dp[a][b]) {
			cout << "1" << "\n";
		}
		else {
			cout << "0" << "\n";
		}
	}
}