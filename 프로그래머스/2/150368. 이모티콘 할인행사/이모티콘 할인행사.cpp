#include <string>
#include <vector>
#include <iostream>
using namespace std;
int cnt = 0;
vector<int> d;
vector<int> v;
vector<vector<int>> u;
vector<int> e;

int maxuser=0;
int maxprice=0;

//현재 v에 이모티콘은 [1300, 1500, 1600, 4900] [10,10,20,30]들어있음
void check(){
    int adduser=0;
    int addprice=0;
    for(int i=0;i<u.size();i++){
        int uprate = u[i][0];
        int upprice = u[i][1];
        int price = 0;
        for(int j=0;j<v.size();j++){
            if(uprate<=v[j]){
                price += (e[j] * (100-v[j]))/100;
            }
        }
        if(price>=upprice){
            adduser++;
        }else{
            addprice += price;
        }
    }
    if(adduser>maxuser){
        maxuser = adduser;
        maxprice = addprice;
    }else if(adduser==maxuser && addprice>maxprice){
        maxuser = adduser;
        maxprice = addprice;
    }
}

void A(int c){
    for(int i=0;i<4;i++){
        v.push_back(d[i]);
        c++;
        if(c<cnt){
            A(c);
        }else{
            check();
        }
        c--;
        v.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    u=users;
    e=emoticons;
    vector<int> answer;
    cnt=emoticons.size();
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_back(40);
    A(0);
    answer.push_back(maxuser);
    answer.push_back(maxprice);
    return answer;
}