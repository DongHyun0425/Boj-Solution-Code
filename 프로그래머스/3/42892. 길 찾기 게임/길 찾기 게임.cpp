#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
    int x;
    int y;
    int num;
    Node * left;
    Node * right;
    Node(int X, int Y , int Num) : x(X),y(Y),num(Num), left(NULL),right(NULL) {}
};

bool cmp(Node A, Node B){
    //조건 1. 층수비교
    //조건 2. x값 비교
    int Astage = A.y;
    int Bstage = B.y;
    int Ax = A.x;
    int Bx = B.x;
    
    if(Astage>=Bstage){
        if(Astage == Bstage){
            if(Ax>Bx){
                return false;
            }
        }
        return true;
    }
    return false;
}

void makeTree(Node * Root, Node * Child){
    if(Root->x > Child -> x){
        if(Root->left == NULL){
            Root->left = Child;
            return;
        }
       makeTree(Root->left,Child);
    }
    
    if(Root->x < Child->x){
        if(Root->right == NULL){
            Root->right = Child;
            return;
        }
        makeTree(Root->right,Child);
    }
    
}

void preOrder(Node * Root,vector<int> & v){
    v.push_back(Root->num);
    if(Root->left !=NULL){
        preOrder(Root->left,v);
    }
    if(Root->right != NULL){
        preOrder(Root->right,v);
    }
}

void postOrder(Node * Root,vector<int> & v){
    if(Root->left !=NULL){
        postOrder(Root->left,v);
    }
    if(Root->right != NULL){
        postOrder(Root->right,v);
    }
    v.push_back(Root->num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> tmp;
    vector<Node> v;
    for(int i=0;i<nodeinfo.size();i++){
        int x = nodeinfo[i][0];
        int y = nodeinfo[i][1];
        int nodeIdx = i+1;
        v.push_back(Node(x,y,nodeIdx));
    }
    
    sort(v.begin(),v.end(),cmp);
  
    for(int i=1;i<v.size();i++){
       makeTree(&v[0], &v[i]);
    }
    
    vector<int>pre;
    preOrder(&v[0],pre);
    
    
    vector<int>post;
    postOrder(&v[0],post);
    
    tmp.push_back(pre);
    tmp.push_back(post);
    
    return tmp;
}