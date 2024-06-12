#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string ans ="";
vector<pair<string,string>> h;

void check(string tmp){
    string t ="";
    for(int i=0;i<tmp.size();i++){
        t+=tmp[i];
        for(auto it : h){
            if(it.first == t){
                ans+=it.second;
                t="";
            }
        }
    }
}

int solution(string s) {
    h.push_back({"zero","0"});
    h.push_back({"one","1"});
    h.push_back({"two","2"});
    h.push_back({"three","3"});
    h.push_back({"four","4"});
    h.push_back({"five","5"});
    h.push_back({"six","6"});
    h.push_back({"seven","7"});
    h.push_back({"eight","8"});
    h.push_back({"nine","9"});
    string tmp ="";
    for(int i=0;i<s.size();i++){
        if('a'<=s[i] && s[i]<='z'){
            tmp+=s[i];
        }else{
            if(tmp.size()>0){
                check(tmp);
                tmp="";
            }
            ans+=s[i];
        }
    }
    check(tmp);
    int answer = stoi(ans);
    return answer;
}