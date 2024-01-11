#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
#include <tuple>

using namespace std;

int graph[26];
string s[10];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string temp = "";
		cin >> temp;
		s[i] = temp;
	}

	for (int i = 0; i < N; i++) {
		//s[0]=gcf
		int p = s[i].size() - 1; //p=2;
		for (int j = 0; j < s[i].size(); j++) {
			int n = s[i][j] - 'A'; //6
			int temp = pow(10, p);//100
			p--;
			graph[n] += temp;
		}
	}

	sort(graph, graph + 26, cmp);
	int k = 0;
	int i = 9;
	int total = 0;
	while (graph[k] != 0) {
		total += graph[k] * i;
		i--;
		k++;
	}
	cout << total;
}