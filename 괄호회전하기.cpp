#include <bits/stdc++.h>
using namespace std;

bool isOkay(string str){
    stack <char> st;
    
    for(int i=0; i<str.size(); i++){
        if(str[i]=='('||str[i]=='{'||str[i]=='['){
            st.push(str[i]);
        }
        else{
            if(st.empty()) return false;
            else{
                if(str[i]==')'){
                    if(st.top()=='(') st.pop();
                    else return false;
                }
                else if(str[i]=='}'){
                    if(st.top()=='{') st.pop();
                    else return false;
                }
                else if(str[i]==']'){
                    if(st.top()=='[') st.pop();
                    else return false;
                }
            }
        }
    }
    
    if(st.empty()) return true;
    else return false;
}

string getStr(string str, int index){
    string result="";
    for(int i=index; i<str.size(); i++){
        result+=str[i];
    }
    for(int i=0; i<index; i++){
        result+=str[i];
    }
    return result;
}

int solution(string s) {
    int answer = 0;
    for(int i=0; i<s.size(); i++){
        if(isOkay(getStr(s,i))) answer++;
    }
    return answer;
}

//프로그래머스:https://programmers.co.kr/learn/courses/30/lessons/76502?language=cpp
