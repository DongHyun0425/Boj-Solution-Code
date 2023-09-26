#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

vector <int> v;

void male(int number, int N) {
	int count = 1;
	while (number * count <= N) {
		if (v[number*count] == 0) {
			v[number*count] = 1;
		}
		else {
			v[number*count] = 0;
		}
		count++;
	}
}


void girl(int number, int N) {
	int start = 1;
	int end = N;
	int gogan = 1;
	while (1) {
		if (number - gogan >= start && number + gogan <= end) {
			if (v[number - gogan] == v[number + gogan]) {
				if (v[number - gogan] == 1) {
					v[number - gogan] = 0;
				}
				else {
					v[number - gogan] = 1;
				}

				if (v[number + gogan] == 1) {
					v[number + gogan] = 0;
				}
				else {
					v[number + gogan] = 1;
				}
				gogan++;
			}
			else {
				if (v[number] == 1) {
					v[number] = 0;
				}
				else {
					v[number] = 1;
				}
				break;
			}
		}
		else {
			if (v[number] == 1) {
				v[number] = 0;
				break;
			}
			else {
				v[number] = 1;
				break;
			}
		}
	}



}

int main(){
	v.push_back(0);
	int N;
	cin >> N;
	for (int i = 0; i < N*2-1; i++) {
		if (i % 2 == 0) {
			int k = 0;
			cin >> k;
			v.push_back(k);
		}
	}
	
	int k = 0;
	cin >> k;

	for (int i = 0; i < k; i++) {
		int sex = 0;
		int number = 0;
		cin >> sex >> number;
		if (sex == 1) {
			male(number,N);
		}
		else {
			girl(number, N);
		}
	}

	for (int i = 1; i < v.size(); i++) {
		cout << v[i] <<" ";
		if (i % 20 == 0) {
			cout << "\n";
		}

	}
}
