#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

string map[64];
vector<char> v;

void findzero(int b, int a, int N) {
	char k = map[b][a];
	for (int i = b; i < b+N; i++) {
		for (int j = a; j < a+N; j++) {
			if (map[i][j] != k) {
				cout << '(';
				findzero(b, a, N / 2);
				findzero(b, a + N / 2, N / 2);
				findzero(b + N / 2, a , N / 2);
				findzero(b + N / 2, a+N/2, N / 2);
				cout << ')';
				return;
			}
		}
	}
	cout << k;
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string k;
		cin >> k;
		map[i] = k;
	}

	findzero(0, 0, N);

}

