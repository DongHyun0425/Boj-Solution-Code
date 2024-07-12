#include <deque>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int tcount = 0;
vector<int>v;
vector<int> fb;
vector<vector<int>>combi;
bool visited[11] = { false, };
vector<int>map[11];
int answer = 100000000;
int popul[11] = { 0, };

void BT(int tmp, int depth) {
	if (fb.size() == depth) {
		combi.push_back(fb);
		return;
	}
	for (int i = tmp; i < v.size(); i++) {
		fb.push_back(v[i]);
		BT(i + 1, depth);
		fb.pop_back();
	}
}

vector<int>dfs_check;
void DFS(int start, int &n) {
	visited[start] = true;
	n += popul[start];
	for (int i = 0; i < map[start].size(); i++) {
		if (!visited[map[start][i]] && find(dfs_check.begin(),dfs_check.end(),map[start][i])!=dfs_check.end()) {
			DFS(map[start][i],n);
		}
	}
}


void solution() {
	for (int i = 0; i < combi.size(); i++) {
		bool flag = true;
		bool total_flag = true;

		vector<int>candi = combi[i];
		vector<int>semi_candi;
		for (int i = 0; i < v.size(); i++) {
			if (find(candi.begin(), candi.end(), v[i]) == candi.end()) {
				semi_candi.push_back(v[i]);
			}
		}

		int candi_num = 0;
		int semi_candi_num = 0;

		dfs_check = candi;
		DFS(candi[0],candi_num);
		dfs_check.clear();
		for (int i = 0; i < candi.size(); i++) {
			if (!visited[candi[i]]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			dfs_check = semi_candi;
			DFS(semi_candi[0],semi_candi_num);
			dfs_check.clear();
			for (int i = 0; i < semi_candi.size(); i++) {
				if (!visited[semi_candi[i]]) {
					total_flag = false;
					break;
				}
			}
		}
		if (!flag) total_flag = false;

		if (total_flag) {
			if (answer > abs(semi_candi_num - candi_num)) {
				answer = abs(semi_candi_num - candi_num);
			}
		}
		else {
			tcount++;
		}

		for (int i = 0; i < 11; i++) {
			visited[i] = false;
		}
	}
}

int main() {
	int zxc = 0;
	cin >> zxc;
	int N = zxc / 2;
	for (int i = 1; i <= zxc; i++) {
		v.push_back(i);
	}
	for (int i = 1; i <= N; i++) {
		BT(0, i);
	}

	for (int i = 1; i <= zxc; i++) {
		int tmp = 0;
		cin >> tmp;
		popul[i] = tmp;
	}

	for (int i = 1; i <= zxc; i++) {
		int x = 0;
		cin >> x;
		for (int j = 0; j < x; j++) {
			int k = 0;
			cin >> k;
			map[i].push_back(k);
		}
	}

	solution();

	if (tcount == combi.size()) {
		cout << -1;
	}
	else {

		cout << answer;
	}
}