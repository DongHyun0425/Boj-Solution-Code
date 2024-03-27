#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(string s) {
    vector <int> map[100000];
    vector<int> answer;
    string temp;
    bool sw = false;
    vector <int> v;
    int cnt = 1;
    for (int i = 1; i < s.size() - 1; i++) {
        if (s[i] == '{') { sw = true; } 
        else if (s[i] == '}') {
            sw = false;
            v.push_back(stoi(temp));
            temp = "";
        }
        else if (sw && s[i] != ',') {
            temp += s[i];
        }else if (sw && s[i] == ',') {
            v.push_back(stoi(temp));
            temp = "";
        }
       else if (!sw && s[i] == ',') {
            for (int i = 0; i < v.size(); i++) {
                map[v.size()].push_back(v[i]);
            }
            cnt++;
            v.clear();
        }
    }

    for (int i = 0; i < v.size(); i++) {
        map[v.size()].push_back(v[i]);
    }

    bool check[100000] = { false, };
    for (int i = 1; i < cnt+1; i++) {
        if (i == 1) {
            answer.push_back(map[i][0]);
            check[map[i][0]] = true;
        }
        else {
            for (int j = 0; j < map[i].size(); j++) {
                if (!check[map[i][j]]) {
                    answer.push_back(map[i][j]);
                    check[map[i][j]] = true;
                }
            }
        }
    }
    return answer;
    
}