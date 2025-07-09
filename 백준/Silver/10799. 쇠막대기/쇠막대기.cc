#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> razer;

int main() {
	string s = " ";
	cin >> s;

	int count = 0;

	for (int i = 0;i < s.size();i++) {
		if (s[i] == '(') { razer.push(s[i]); }
		else {
			if (s[i] == ')' && s[i - 1] == '(') {
				razer.pop(); count += razer.size();
			}
			else if (s[i] == ')') { razer.pop(); count++; }
		}
	}
	cout << count;
}