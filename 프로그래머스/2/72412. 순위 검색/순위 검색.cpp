#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;
vector<string>v;
unordered_map<string, vector<int>> um;

void addCases(vector<string> words, int score, int tmp) {
    if (v.size() == 4) {
        string s = "";
        for (int i = 0; i < 4; i++) {
            s += v[i];
        }
        um[s].push_back(score);
        return;
    }

       v.push_back(words[tmp]);
        addCases(words, score, tmp + 1);
        v.pop_back();

        v.push_back("-");
        addCases(words, score, tmp + 1);
        v.pop_back();
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<string> words(5);
    for (auto str : info)
    {
        istringstream iss(str);// 지원자의 정보를 스트림으로 변형시켜 공백 기준으로 나눌때 간단히 나눠준다.
        iss >> words[0] >> words[1] >> words[2] >> words[3] >> words[4];
        addCases(words, stoi(words[4]),0);
    }
    
    unordered_map<string, vector<int>>::iterator iter = um.begin();
    for (iter; iter != um.end(); iter++) sort(iter->second.begin(), iter->second.end());
    
    for (auto q : query)
    {
        int idx = 0;
        istringstream iss(q);
        iss >> words[0] >> words[4] >> words[1] >> words[4] >> words[2] >> words[4] >> words[3] >> words[4];
        vector<int> scores = um[words[0]+words[1]+words[2]+words[3]];
        if (scores.empty())
        {
            answer.push_back(0);
            continue ;
        }
        //sort(scores.begin(),scores.end()); 여기서 정렬을 하면 100,000번 하게 될 수도 있다.....
        idx = lower_bound(scores.begin(), scores.end(), stoi(words[4])) - scores.begin();
        answer.push_back(scores.size() - idx);//총인원수에서 조건보다 낮은 점수 인원 빼주기
    }
    return answer;
}