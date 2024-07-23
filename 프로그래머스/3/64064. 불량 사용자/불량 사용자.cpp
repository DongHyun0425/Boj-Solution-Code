#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

set<string>st;


bool mycheck(string target,string ban){
    if(target.size()!=ban.size()) return false;
    for(int i=0;i<target.size();i++){
            if(ban[i]=='*'){
                continue;
            }else if(ban[i]!=target[i]){
                return false;
            }
    }
    return true;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    sort(user_id.begin(),user_id.end());
    do{
        vector<string> banned_tmp;
        banned_tmp = banned_id;
        vector<string> myfind;
        for(int i=0;i<user_id.size();i++){
            string target = user_id[i];
            for(int j=0;j<banned_tmp.size();j++){
                if(mycheck(target,banned_tmp[j])){
                    myfind.push_back(target);
                    banned_tmp.erase(banned_tmp.begin()+j);
                    j--;
                    break;
                }
            }
          
        }
        sort(myfind.begin(),myfind.end());
        if(banned_tmp.size()==0){
              string tmp="";
        for(int i=0;i<myfind.size();i++){
            tmp+=myfind[i];
        }
            st.insert(tmp);
        }
    }while(next_permutation(user_id.begin(),user_id.end()));
    return st.size();
}