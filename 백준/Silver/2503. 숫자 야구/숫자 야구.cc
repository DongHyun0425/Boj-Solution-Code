#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int strike(string a, string b) {
	int strike=0;
	for (int i = 0; i < 3; i++) {
		if (a[i] == b[i]) {
			strike++;
		}
	}
	return strike;
}

int ball(string a, string b) {
	int ball=0;
	if (a[0] == b[1]) { ball ++;}
	if (a[0] == b[2]) { ball++; }
	if (a[1] == b[0]) { ball++; }
	if (a[1] == b[2]) { ball++; }
	if (a[2] == b[0]) { ball++; }
	if (a[2] == b[1]) { ball++; }

	return ball;
}

int main(){
	vector <int> sample;
	for (int i = 123; i < 999; i++) {
		string k = to_string(i);
		if (k[0]!='0'&& k[1] != '0' && k[2] != '0' && k[0] != k[1] && k[1] != k[2] && k[0] != k[2]) {
			sample.push_back(i);
		}
	}

	vector < pair <int, pair <int, int >>> v2;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int k = 0;
		int s = 0;
		int b = 0;
		cin >> k >> s >> b;
		v2.push_back({ k,{s,b} });
	}
	int result = 0;
	for (int i = 0; i < sample.size(); i++) {
		string k = to_string(sample[i]);
		//string k = "324";
		int posibility = 0;
		for (int i = 0; i < N; i++) {
			string bigo = to_string(v2[i].first);
			int s = strike(k, bigo);
			int b = ball(k, bigo);
			if (s==v2[i].second.first && b==v2[i].second.second) {
				posibility++;
			}
			else {
				break;
			}
		}
		if (posibility == N) { result++; }
	}
	cout << result;
}













