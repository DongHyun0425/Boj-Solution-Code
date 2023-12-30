#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
vector <int> Note;

void binary_search(int target, int start, int end) {
	int temp = 0;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (Note[mid] == target) { cout << 1 << "\n"; temp++; break; }
		else if (Note[mid] > target) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	if (temp == 0) {
		cout << 0 << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T = 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int a = 0;
		cin >> a;
		for (int i = 0; i < a; i++) {
			int k = 0;
			cin >> k;
			Note.push_back(k);
		}
		sort(Note.begin(), Note.end());

		int b = 0;
		cin >> b;
		for (int i = 0; i < b; i++) {
			int k = 0;
			cin >> k;
			binary_search(k, 0, a-1);
		}
		Note.clear();
	}

}