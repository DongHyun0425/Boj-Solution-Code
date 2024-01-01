#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector <int> v;
	int N = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		v.push_back(i);
	}
	
	sort(v.begin(), v.end());

	do
	{
		for (int i = 0; i < v.size(); i++)
		{
				cout << v[i] << " ";
		}
		cout << '\n';
	} while (next_permutation(v.begin(), v.end()));

}