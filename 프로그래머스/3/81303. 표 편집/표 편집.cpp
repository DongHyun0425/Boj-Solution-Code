#include <vector>
#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

struct Node{
    int n;
    Node * prev;
    Node * next;
    Node(int n, Node* prev, Node* next) : n(n), prev(prev), next(next){}
};

stack<Node*> stk;

string solution(int n, int k, vector<string> cmd) {
    string answer(n,'X');
    
    Node* it = new Node(0,NULL,NULL);
    Node* cur = it;
    
    for(int i=1;i<n;i++){
        it->next = new Node(i,it,NULL);
        it = it->next;
        if(i==k) cur = it;
    }
    
    for(auto c: cmd){
        if(c[0] == 'U'){
            int num = stoi(c.substr(2,8));
            for(int i=0;i<num;i++){
                cur = cur -> prev;
            }
        }else if(c[0]=='D'){
            int num = stoi(c.substr(2,8));
            for(int i=0;i<num;i++){
                cur = cur -> next;
            }
        }else if(c[0]=='C'){
            stk.push(cur);
            
            //중간 노드삭제
            if(cur -> prev !=NULL){
                cur -> prev -> next = cur -> next;
            }
            if(cur -> next !=NULL){
                cur -> next -> prev = cur -> prev;
            }
            //마지막노드는 cur을 앞으로 나머지는 cur을 한칸 뒤로
            if(cur -> next == NULL) cur = cur -> prev;
            else cur = cur -> next;
        }else{
            Node * repair = stk.top();
            
            if(repair -> next != NULL) repair -> next ->prev = repair;
            if(repair -> prev != NULL) repair -> prev -> next = repair;
            stk.pop();
        }
    }
    while(cur -> prev != NULL) cur = cur -> prev;
    while(cur != NULL){
        answer[cur -> n] = 'O';
        cur = cur -> next;
    }
    return answer;
}