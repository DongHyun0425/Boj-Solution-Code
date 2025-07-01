#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
int root;
vector<int>tree[52];
int cnt;
int erase;
void dfs(int num) {
	if (tree[num].size() == 0) {
		cnt++;
		return;
	}

	for (int i = 0; i < tree[num].size(); i++) {
		if (tree[num][i] != erase) {
			dfs(tree[num][i]);
		}
		else {
			if (tree[num].size() == 1) cnt++;
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		if (tmp == -1) {
			root = i;
		}
		else {
			tree[tmp].push_back(i);
		}
	}
	cin >> erase;

	if (root == erase) {
		cout << 0;
	}
	else {
		dfs(root);
		cout << cnt;
	}
}