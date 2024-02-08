#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <iostream>
#include <algorithm>
using namespace std;
vector<bool> visited;
vector<int>v;
int n = 0;
int target = 0;
int answer = 0;
void BT(int start,int result){
	
	if (start==n) {
		return;
	}
	
	for (int i = start; i < n; i++) {
		result += v[i];
		if (result == target) {
			answer++;
	    }
		visited[i] = true;
		BT(i + 1, result);
		visited[i] = false;
		result -= v[i];
	}
}
int main() {
	cin >> n;
	cin >> target;

	for (int i = 0; i < n; i++) {
		int temp = 0;
		cin >> temp;
		v.push_back(temp);
		visited.push_back(false);
	}
	
	BT(0,0);
	cout << answer;
}