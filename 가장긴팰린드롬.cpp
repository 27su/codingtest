// 프로그래머스 : https://programmers.co.kr/learn/courses/30/lessons/12904

#include <bits/stdc++.h>
using namespace std;

int solution(string s)
{
    int len=s.size();
    
    while(len>1){ // 검사해보려는 문자열의 길이
        for(int i=0; i<=s.size()-len; i++){ // left와 right를 오른쪽으로 한칸씩 이동
            int l=i,r=len+i-1;
            bool flag = true;
            while(l<r){ // 실제로 펠린드롬인지 확인
                if(s[l]!=s[r]){
                    flag = false;
                    break;
                }
                l++;
                r--;
            }
            if(flag) return len;
        }
        len--;
    }

    return 1;
}
