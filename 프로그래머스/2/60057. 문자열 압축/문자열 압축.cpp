#include <string>
#include <vector>
#include <iostream>

using namespace std;
int result = 100000;

int solution(string s) {
    if(s.size()==1) return 1;else{
    for (int cnt = 1; cnt <= s.size() / 2; cnt++) {
        
        vector<string> v;
        string temp = "";
        for (int i = 0; i < s.size(); i++) {
            temp += s[i];
            if (i % cnt == cnt - 1) {
           
                v.push_back(temp);
                temp = "";
            }
        }
        if (temp.size() > 0) {
  
            v.push_back(temp);
        }
        string k = "";
        int count = 1;

        for (int i = 0; i < v.size()-1; i++) {
            if (v[i] == v[i + 1]) {
                count++;
            }
            else if (count > 1) {
                string temp = to_string(count) + v[i];
                k += temp;
                count = 1;
            }
            else {
                k += v[i];
            }
        }
        if (count > 1) {
            string temp = to_string(count) + v[v.size()-1];
            k += temp;
        }
        else {
            k += v[v.size()-1];
        }
        if (result > k.size()) {
            result = k.size();
        }
    }
    return result;
    }
}