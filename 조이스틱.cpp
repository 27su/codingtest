//프로그래머스 : https://programmers.co.kr/learn/courses/30/lessons/42860

#include <bits/stdc++.h>
using namespace std;

vector <int> d;
string str, target;
int answer = INT_MAX;
vector <bool> check;

void getResult(int index, int n){
    n += d[target[index]-'A'];
    str[index] = target[index];
    if(str == target){
        answer = min(answer,n);
        str[index] = 'A';
        return;
    }
    
    int next = index-1;
    if(next<0) next = target.size()-1;
    if(!check[next]){
        check[next] = true;
        getResult(next, n+1);
        check[next] = false;
    }
    
    
    next = index+1;
    if(next>target.size()-1) next = 0;
    if(!check[next]){
        check[next] = true;
        getResult(next, n+1);
        check[next] = false;
    }
    
    str[index] = 'A';
}

int solution(string name) {
    check.assign(name.size()+1,0);
    for(int i=0; i<name.length(); i++) str += "A";
    target = name;
    for(int i=0; i<26; i++){
        int b = abs('A'+i - 'Z') + 1;
        if(i>b) d.push_back(b);
        else d.push_back(i);
    }
    
    getResult(0,0);
    
    return answer;
}
