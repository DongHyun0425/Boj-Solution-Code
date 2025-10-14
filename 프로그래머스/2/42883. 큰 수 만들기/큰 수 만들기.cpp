#include <string>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<int>st;
    for(int i=0;i<number.size();i++){
        int num = number[i]-'0';
        while(!st.empty()){
            if(k>0 && st.top() < num){
                k--;
                st.pop();
            }else break;
        }
        st.push(num);
    }
    
    stack<int>st1;
    
    if(k>0){
        while(k!=0){
            st.pop();
            k--;
        } 
    }
    while(!st.empty()){
        st1.push(st.top());
        st.pop();
    }
    
    while(!st1.empty()) {
        answer+=to_string(st1.top());
        st1.pop();
    }
    
    return answer;
}