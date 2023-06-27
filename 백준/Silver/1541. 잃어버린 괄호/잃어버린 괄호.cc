#include <iostream>
#include <string>
using namespace std;

int main() {
	string a;
	cin >> a;
	string temp;
	int result=0;
	
	int N = a.length();
	int i=-1;
	int check = 0;

	while (i<N-1) {
		i++;
		if (a[i] != '+' && a[i] != '-') {
			temp += a[i];
		}
		else if (a[i] == '+') {
			int num = stoi(temp);
			result += num;
			temp = "";
		}
		else { 
			int num = stoi(temp);
			result += num;
			temp = ""; 
			break; 
		}
	}

	while (i < N-1) {
		check++;
		i++;
		if (a[i] != '+' & a[i] != '-') {
			temp += a[i];
		}
		else {
			int num = stoi(temp);
			result -= num;
			temp = "";
		}
	}
	if (check != 0) {
		int num = stoi(temp);
		result -= num;
		cout << result;
	}
	else {
		int num = stoi(temp);
		result += num;
		cout << result;
	}
	return 0;
}