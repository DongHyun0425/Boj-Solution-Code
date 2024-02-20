#include <vector>
using namespace std;

int map[61][61] = { 0, };
int ssize = 0;
int lssize = 0;
bool ch = false;
bool checkmap() {
	int cnt = 0;
	for (int i = ssize - 1; i < lssize + ssize-1; i++) {
		for (int j = ssize - 1; j < lssize + ssize-1; j++) {
			if (map[i][j] == 1) {
				cnt++;
			}
		}
	}
	if (cnt == lssize * lssize) return true;
	return false;
}

void movemap(vector<vector<int>>& key) {
	for (int i = 0; i < lssize+ssize-1; i++) {
		for (int j = 0; j < lssize + ssize - 1; j++) {
			int tm[61][61] = { 0, };
			for (int i = 0; i < 61; i++) {
				for (int j = 0; j < 61; j++) {
					tm[i][j] = map[i][j];
				}
			
			}

			bool donotcheck = true;
			for (int t = i; t < i + ssize; t++) {
				for (int tt = j; tt < j + ssize; tt++) {
					if (key[t - i][tt - j] == 1 && map[t][tt] == 1) {
						donotcheck = false;
					}
					if (key[t - i][tt - j] == 1) {
						map[t][tt] = key[t - i][tt - j];
					}
				}
			}
			if (donotcheck&&checkmap()) {
				ch = true;
				return;
			}

			for (int i = 0; i < 61; i++) {
				for (int j = 0; j < 61; j++) {
					map[i][j] = tm[i][j];
				}

			}
		}
	}
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	ssize = key.size();
	lssize = lock.size();

	//map에다 lock박기
	for (int i = ssize - 1; i < lssize+ssize-1; i++) {
		for (int j = ssize - 1; j < lssize+ssize-1; j++) {
			map[i][j] = lock[i - ssize + 1][j - ssize + 1];
		}
	}

	vector<vector<int>> tk(ssize, vector<int>(ssize, 0));
	for (int i = 0; i < ssize; i++) {
		for (int j = 0; j < ssize; j++) {
			tk[i][j] = key[i][j];
		}
	}
	movemap(tk);
	if (ch == true) {
		return true;
	}

	for (int i = 0; i < ssize; i++) {
		for (int j = 0; j < ssize; j++) {
			tk[j][ssize - 1 - i] = key[i][j];
		}
	}
	movemap(tk);
	if (ch == true) {
		return true;
	}

	for (int i = 0; i < ssize; i++) {
		for (int j = 0; j < ssize; j++) {
			key[j][ssize - 1 - i] = tk[i][j];
		}
	}
	movemap(key);
	if (ch == true) {
		return true;
	}
	for (int i = 0; i < ssize; i++) {
		for (int j = 0; j < ssize; j++) {
			tk[j][ssize - 1 - i] = key[i][j];
		}
	}
	movemap(tk);
	if (ch == true) {
		return true;
	}
    return false;
}