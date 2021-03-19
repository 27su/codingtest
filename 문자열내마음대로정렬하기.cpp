#include <bits/stdc++.h>

using namespace std;

int N;
bool cmp(string a, string b){
    if(a[N]==b[N]) return a<b;
    else return a[N]<b[N];
}

vector<string> solution(vector<string> strings, int n) {
    N = n;
    sort(strings.begin(), strings.end(), cmp);
    return strings;
}

//프로그래머스 : https://programmers.co.kr/learn/courses/30/lessons/12915
