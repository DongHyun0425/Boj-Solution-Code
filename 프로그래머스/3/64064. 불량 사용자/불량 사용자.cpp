#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool correct(string bid, string uid){
    for(int i=0;i<bid.size();i++){
        if(bid[i]=='*'){
            continue;
        }else if(bid[i]!=uid[i]){
            return false;
        }
    }
    return true;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    vector <int> v;
    for(int i=0;i<user_id.size();i++){
        v.push_back(i);
    }
    set<string> s;
    do{
        vector<string> target;
        vector<string> myfind;
        for(int i=0;i<banned_id.size();i++){
            target.push_back(banned_id[i]);
        }
        
        for(int i=0;i<v.size();i++){
            string uid=user_id[v[i]];
            for(int j=0;j<target.size();j++){
                string temp = target[j];
                if(temp.size()==uid.size() && correct(temp,uid)){
                    target.erase(target.begin()+j);
                    myfind.push_back(uid);
                    break;
                }
            }
        }
        
        if(myfind.size()==banned_id.size()){
        sort(myfind.begin(),myfind.end());
        string tmp="";
        for(int i=0;i<myfind.size();i++){
            tmp+=myfind[i];
        }
        s.insert(tmp);
        }
        
    }while(next_permutation(v.begin(),v.end()));
    
    return s.size();
}