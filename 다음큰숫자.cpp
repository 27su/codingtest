//프로그래머스 : https://programmers.co.kr/learn/courses/30/lessons/12911
//참고 : https://hellowoori.tistory.com/52

#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    int num = bitset<20>(n).count(); //bitset 중에서 1인 비트의 개수를 반환
    while (bitset<20>(++n).count() != num); 
    return n;
}
