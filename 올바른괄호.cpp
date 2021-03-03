//프로그래머스 : https://programmers.co.kr/learn/courses/30/lessons/12909

#include<bits/stdc++.h>
using namespace std;

bool solution(string s)
{
    
    stack <char> st;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='(') st.push(s[i]);
        else{
            if(st.empty()) return false;
            st.pop();
        }
    }
    if(st.empty()) return true;
    else return false;
}
