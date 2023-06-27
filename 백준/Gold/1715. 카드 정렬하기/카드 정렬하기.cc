#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	int result = 0;
	int n;
	cin >> n;
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;
		int temp = -number;
		pq.push(temp);
	} 

	int real = 0;

	while (pq.size() > 1) {
		int temp = -pq.top();
		pq.pop();
		int temp2 = -pq.top();
		pq.pop();
		result = temp + temp2;
		real += result;
		pq.push(-result);
	}
	if (n == 1) { cout << 0; }
	else {
		cout << real;
	}
	return 0;
}
