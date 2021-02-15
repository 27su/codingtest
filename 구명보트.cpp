//프로그래머스 : https://programmers.co.kr/learn/courses/30/lessons/42885

#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int n = 0;
    int start=0, end=people.size()-1;
    while(n<people.size()){
        if(people[start]+people[end]>limit){
            answer++;
            n += 1;
            end--;
        }
        else{
            answer++;
            n += 2;
            end--;
            start++;
        }
    }
    return answer;
}
