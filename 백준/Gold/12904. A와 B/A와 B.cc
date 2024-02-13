#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string target = "";
	string s = "";
	cin >> target >> s;
	int firstfind = 0;
	if (target == s) firstfind++;
	int ffind = 0;
	while (s.size() > 0) {
		if (s[s.size() - 1] == 'A') {
			s.erase(s.begin() + s.size() - 1);
		}
		else {
			string temp = "";
			s.erase(s.begin() + s.size() - 1);
			for (int i = s.size()-1; i >= 0; i--) {
				temp += s[i];
			}
			s = "";
			for (int i = 0; i < temp.size(); i++) {
				s += temp[i];
			}
		}
		if (target == s) {
			ffind++;
		}
	}
	if (ffind > 0 || firstfind>0) {
		cout << 1;
	}
	else {
		cout << 0;
	}
}