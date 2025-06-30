
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n;

int N;

void sol(int target, int step, int before_length) {
	//처음 moo에서 찾을 수 있는경우
	if (target <= 3) {
		if (target == 1) {
			cout << "m";
			return;
		}
		cout << "o";
		return;
	}

	int next_step = step + 1;
	//늘려야하는경우 ex).moo mooo moo
	// before_length는 moo로 3, next_step은 mooo
	if (target > before_length * 2 + next_step + 3) {
		sol(target, next_step, before_length * 2 + next_step + 3);
	}
	else if (target > before_length) {
		//해당 단계에서 찾을 수 있는경우
		if (target - before_length <= step + 3) {
			if (target - before_length == 1) {
				cout << "m";
				return;
			}
			cout << "o";
			return;
		}
		else {
			sol(target - (before_length + next_step + 3), 0, 3);
		}
	}
}

int main() {
	cin >> N;

	sol(N, 0, 3);
}