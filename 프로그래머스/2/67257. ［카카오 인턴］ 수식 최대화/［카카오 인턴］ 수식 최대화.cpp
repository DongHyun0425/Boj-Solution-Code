#include <deque>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

vector <long long>numss;
vector <char>opp;
vector<long long>s1;
vector<char>s2;
long long answer = 0;
vector<char>v = { '+','-','*' };


long long solution(string expression) {
	string n = "";
	for (int i = 0; i < expression.size(); i++) {
		if (expression[i] != '+' && expression[i] != '-' && expression[i] != '*') {
			n += expression[i];
		}
		else {
			numss.push_back(stoi(n));
			n = "";
			opp.push_back(expression[i]);
		}
	}
	numss.push_back(stoi(n));

	sort(v.begin(), v.end());
	do {
		vector <long long>nums;
		vector <char>op;
		nums = numss;
		op = opp;

		for (int i = 0; i < v.size(); i++) {
			char w = v[i];
			for (int j = 0; j < op.size(); j++) {
				if (op[j] == w) {
					if (w == '*') {
						long long tmp = nums[j] * nums[j + 1];
						nums[j] = tmp;
						nums.erase(nums.begin()+j+1);
						op.erase(op.begin() + j);
						j--;
					}
					else if (w == '+') {
						long long tmp = nums[j] + nums[j + 1];
						nums[j] = tmp;
						nums.erase(nums.begin() + j + 1);
						op.erase(op.begin() + j);
						j--;
					}
					else {
						long long tmp = nums[j] - nums[j + 1];
						nums[j] = tmp;
						nums.erase(nums.begin() + j + 1);
						op.erase(op.begin() + j);
						j--;

					}
				}
			}
		}

		if (abs(nums[0]) > answer) {
			answer = abs(nums[0]);
		}

	} while (next_permutation(v.begin(), v.end()));
    return answer;
}