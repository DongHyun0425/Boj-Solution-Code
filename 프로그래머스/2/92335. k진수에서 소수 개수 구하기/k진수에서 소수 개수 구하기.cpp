#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int answer=0;
string number = "0123456789ABCDEF";				//16진수 까지의 가능한 각 자리 수 

string change(int num, int binary) {			//num = n, binary = k
    string result;								//변환 결과
    if (num == 0) {
        return "0";								//num이 0일경우 0반환
    }
    while (num > 0) {
        result = number[num % binary] + result;	//16진수까지의 변환 number이용하여 reverse 사용하지 않음.
        num /= binary;							//진수 계산.
    }

    return result;
}

bool isPrime(long long n) {
    if(n==1) return false;
	for (int i = 2; i <= sqrt(n); i++) {//2~n의 제곱근까지
		if (n%i == 0) {//i가 n의 약수라면 소수가 아니므로 false return
			return false;
		}
	}
	//2 ~ n-1까지 약수가 없다면 소수이므로, true return
	return true;
}


int solution(int n, int k) {
    string s = change(n,k);
    string check="";
    for(long long i=0;i<s.size();i++){
        if(s[i]!='0'){
            check+=s[i];
        }else if(check.size()>0){
            if(isPrime(stol(check))){
                answer++;
                check="";
            }
            check="";
        }
    }
    
    if(check.size()>0 && isPrime(stol(check))) {
        answer++;
    }
    
    return answer;
}