
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
#include <tuple>
#include <map>

using namespace std;

map <string, int> mymap;
int givetake[50][50] = { 0, };
int jisu[50][3] = { 0, };
int solution(vector<string> friends, vector<string> gifts) {
    	int answer = 0;
	int cnt = 0;
	//1
	for (int i = 0; i < friends.size(); i++) {
		mymap.insert(make_pair(friends[i], cnt));
		cnt++;
	}
	//2
	for (int i = 0; i < gifts.size(); i++) {
		string a = "";
		string b = "";
		int char_count = 0;
		for (int j = 0; j < gifts[i].size(); j++) {
			if (gifts[i][j] == ' ') { char_count++; continue; }
			if (char_count == 0) {
				a += gifts[i][j];
			}
			else {
				b += gifts[i][j];
			}
		}

		int a_, b_ = 0;
		for (int i = 0; i < mymap.size(); i++) {
			auto it = mymap.find(a);
			a_ = it -> second;
		}
		for (int i = 0; i < mymap.size(); i++) {
			auto it = mymap.find(b);
			b_ = it->second;
		}
		givetake[a_][b_] += 1;
	}
	//3
	for (int i = 0; i < friends.size(); i++) {
		int a_ = 0;
		for (int j = 0; j < mymap.size(); j++) {
			auto it = mymap.find(friends[i]);
			a_ = it->second;
		}
		int give = 0;  int get = 0;
		for (int x = 0; x < friends.size(); x++) {
			give += givetake[a_][x];
			get += givetake[x][a_];
		}
		jisu[i][0] = give;
		jisu[i][1] = get;
		jisu[i][2] = give-get;
	}
	//4
	int result[50] = { 0, };
	for (int i = 0; i < friends.size(); i++) {
		for (int j = 0; j < friends.size(); j++) {
			int give = givetake[i][j];
			int get = givetake[j][i];
			if (give > get) {
				result[i] += 1;
			}
			else if (give < get) {
				result[j] += 1;
			}
			else if ((give == 0 && get == 0) || (give == get)) {
				if (jisu[i][2] > jisu[j][2]) {
					result[i] += 1;
				}
				else if (jisu[i][2] < jisu[j][2]) {
					result[j] += 1;
				}
			}
		}
	}

	for (int i = 0; i < 50; i++) {
		if (result[i] > answer) {
			answer = result[i];
		}
	}
	return answer/2;
}