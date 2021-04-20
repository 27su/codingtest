#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(),d.end());
    for(int i=0; i<d.size(); i++){
        if(budget>=d[i]){
            budget -= d[i];
            answer++;
        }
        else break;
    }
    return answer;
}

//프로그래머스 : https://programmers.co.kr/learn/courses/30/lessons/12982
