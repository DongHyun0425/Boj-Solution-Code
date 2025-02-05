#include <iostream>
#include <vector>
using namespace std;

struct TrieNode {
	TrieNode* children[10];
	bool isEnd;

	TrieNode() : children(), isEnd(false) {}

	void Insert(string& key, int index) {
		//ABC입력시 C에다가 
		if (index == key.length()) {
			isEnd = true;
		}
		else {
			int next = key[index] - '0';
			if (children[next] == nullptr) {
				children[next]= new TrieNode;
			}
			children[next]->Insert(key, index + 1);
		}
	}

	bool Find(string& key, int depth) {
		if (depth == key.length()) {
			return false;
		}

		if (isEnd) return true;

		int next = key[depth] - '0';
		if (children[next] == nullptr) return false;
		return children[next]->Find(key, depth + 1);
	}
};

int main() {
	int T = 0;
	cin >> T;
	for (int t = 0; t < T; t++) {
		TrieNode root;
		int N = 0;
		cin >> N;
		vector<string> v;
		for (int i = 0; i < N; i++) {
			string s = "";
			cin >> s;
			v.push_back(s);
			root.Insert(s, 0);
		}

		bool flag = false;
		for (auto t : v) {
			if (root.Find(t, 0)) {
				cout << "NO" << "\n";
				flag = true;
				break;
			}
		}
		if (!flag) {
			cout << "YES" << "\n";
		}

	}
}