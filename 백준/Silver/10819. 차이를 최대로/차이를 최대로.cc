#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N = 0;
	vector<int> v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp = 0;
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());
	int answer = 0;
	do
	{
		vector<int>c;
		int tmp = 0;
		for (int i = 0; i < v.size(); i++)
		{
			c.push_back(v[i]);
		}
		for (int i = 0; i < N-1; i++) {
			tmp += abs(c[i] - c[i + 1]);
		}
		if (answer < tmp) answer = tmp;
	} while (next_permutation(v.begin(), v.end()));
	cout << answer;
}