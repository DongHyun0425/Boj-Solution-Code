#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <deque>

using namespace std;
int main() {
	int T = 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int a = 0;
		cin >> a;

		deque<long long>dq;
		for (int x = 0; x < a; x++) {
			int temp = 0;
			cin >> temp;

			dq.push_front(temp);
		}

		deque<long long>::iterator iter;
		int max = 0;
		long long answer = 0;
		for (iter = dq.begin(); iter != dq.end(); iter++) {
			if (iter == dq.begin()) {
				max = *iter;
			}
			else if (*iter < max) {
				answer += (max - *iter);
			}
			else {
				max = *iter;
			}
		}
		cout << answer << "\n";
	}
}