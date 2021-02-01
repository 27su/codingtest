//프로그래머스 : https://programmers.co.kr/learn/courses/30/lessons/72410

#include <bits/stdc++.h>

using namespace std;

string solution(string new_id) {
    string answer = "";
    for(int i=0; i<new_id.length(); i++) new_id[i] = tolower(new_id[i]);
    for(int i=0; i<new_id.length(); i++){
        if('a'<=new_id[i]&&new_id[i]<='z' || '0'<=new_id[i]&&new_id[i]<='9' || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') answer += new_id[i];
    }
    
    int cnt=0;
    for(int i=0; i<answer.length();){
        if(answer[i]=='.') cnt++;
        else cnt = 0;
        if(cnt>=2) { answer.erase(i,1);}
        else i++;
    }
    
    if(answer[0] == '.') answer.erase(0,1);
    if(answer[answer.length()-1] == '.') answer.erase(answer.length()-1,1);
    
    if(answer.length()==0) answer = "a";
    
    if(answer.length()>=16) {
        answer.erase(15);
        if(answer[answer.length()-1] == '.') answer.erase(answer.length()-1,1);
    }
    
    while(answer.length()<=2){
        answer += answer[answer.length()-1];
    } 
    return answer;
}
