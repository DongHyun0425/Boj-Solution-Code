#include <iostream>
#include <vector>

using namespace std;

int map[1010][1010];

int main() {
	int n = 0;
	int m = 0;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		string s = "";
		cin >> s;
		for (int j = 0; j <= s.size(); j++) {
			map[i][j+1] = s[j] - '0';
		}

	}

	int answer = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 1) {
				int tmp = 2000;
				if (map[i - 1][j - 1] < tmp) tmp = map[i - 1][j - 1];
				if (map[i][j - 1] < tmp) tmp = map[i][j - 1];
				if (map[i - 1][j] < tmp) tmp = map[i - 1][j];

				map[i][j] = tmp + 1;
				if (tmp + 1 > answer) answer = tmp + 1;
			}
		}
	}

	cout << answer * answer << endl;
	return 0;
}