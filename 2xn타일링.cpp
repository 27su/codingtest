//프로그래머스 : https://programmers.co.kr/learn/courses/30/lessons/12900

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int p = 1;
    int q = 1;
    for(int i=2; i<=n; i++){
        answer = (p+q)%1000000007;
        p = q;
        q = answer;
    }
    return answer%1000000007;
}