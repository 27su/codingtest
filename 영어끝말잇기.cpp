#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> v;
    int total = words.size();
    for(int i=0; i<total; i++){
        if(find(v.begin(),v.end(),words[i]) != v.end() || i!=0 && words[i-1][words[i-1].size()-1] != words[i][0]){
            answer.push_back(i%n+1);
            answer.push_back(i/n+1);
            break;
        }
        v.push_back(words[i]);
    }
    if(answer.size()==0){answer.push_back(0); answer.push_back(0);}
    return answer;
}

//프로그래머스 : https://programmers.co.kr/learn/courses/30/lessons/12981
