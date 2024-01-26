#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<unsigned long long int>result;
int main() {
	result.push_back(1);
	result.push_back(3);
	unsigned long long int n = 0;
	cin >> n;
	
		for (int i = 2; i <= n; i++) {
			result.push_back((result[i - 1] * 2 + result[i - 2] )% 9901);
		}
	
	cout << result[n];
}