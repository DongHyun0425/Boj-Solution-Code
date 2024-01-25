#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
#include <tuple>
#include <map>
#include <unordered_set> 
using namespace std;

vector<long long int> amount;
vector<long long int> dist;
long long int amt = 0;
long long int total = 0;


int main() {
	cin >> amt;
	dist.push_back(0);
	for (int i = 0; i < amt - 1; i++) {
		int temp = 0;
		cin >> temp;
		dist.push_back(temp);
	}
	for (int i = 0; i < amt; i++) {
		int temp = 0;
		cin >> temp;
		amount.push_back(temp);
	}

	long long current = amount[0];
	total += current * dist[1];

	for (int i = 1; i < amt-1; i++) {
		if (current < amount[i]) {
			total += current * dist[i + 1];
		}
		else {
			current = amount[i];
			total += current * dist[i + 1];
		}
	}
	cout << total;
}