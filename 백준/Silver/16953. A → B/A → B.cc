#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int A;
	int B;
	cin >> A >> B;
	queue <long> q;
	queue <long> q2;
	q.push(A);
	int count=0;
	int check = 0;
	int k = 2;

	while (1) {
		if (q.size() > 0) {
			while (1) {
				long a = q.front();
				q.pop();
				long b = a * 2;
				if (b == B) { cout << count + 2; check++; break; }
				else if (b < B) { q2.push(b); }
				long c = a * 10 + 1;
				if (c == B) { cout << count + 2; check++; break; }
				else if (c < B) { q2.push(c); }

				if (q.size() == 0) { count++; break; }
			}
		}
		else {
			while (1) {
				long a = q2.front();
				q2.pop();
				long b = a * 2;
				if (b == B) { cout << count + 2; check++; break; }
				else if (b < B) { q.push(b); }
				long c = a * 10 + 1;
				if (c == B) { cout << count + 2; check++; break; }
				else if (c < B) { q.push(c); }

				if (q2.size() == 0) { count++; break; }
			}
		}
		if (check > 0) { break; }
		if (q.size() == 0 && q2.size() == 0) { break; }
	}
	if (check == 0) { cout << -1; }
    return 0;
	
}