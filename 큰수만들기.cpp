// 백준 : https://programmers.co.kr/learn/courses/30/lessons/42883

#include <bits/stdc++.h>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    
     //필요한 글자수만큼 반복하기
    for (int j = 0, index = 0; j < number.length() - k; j++) {
        char max = 0;
        //앞에서 남겨야 되는 숫자 중에 제일 큰수 체크
        for (int i = index; i <= k + j; i++) {
            if (max < number[i]) {
                index = i+1;
                max = number[i];
            }
        }
        //제일 큰수를 정답에 추가
        answer += max;
    }
    
    return answer;
}
