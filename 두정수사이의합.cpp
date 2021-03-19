#include <bits/stdc++.h>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    if(a>b) swap(a,b);
    for(int i=a; i<=b; i++) answer += i;
    return answer;
}

//프로그래머스 : https://programmers.co.kr/learn/courses/30/lessons/12912
