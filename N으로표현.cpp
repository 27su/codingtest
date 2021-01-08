//프로그래머스 : https://programmers.co.kr/learn/courses/30/lessons/42895

#include <string>
#include <vector>

using namespace std;

int answer = 9;

void dfs (int cnt, int num, int N, int number){
    if(cnt >= 9) return;
    if(num == number){
        answer = min(answer, cnt);
        return;
    } 
    // 숫자 1자리부터 8자리 까지 반복
    int x=0;
    for(int i=0;i<8;i++){
        x = (x*10) + N; // 1자리부터 8자리까지
        // cnt에 사용 수 만큼 더해주기
        dfs(cnt+i+1, num+x, N, number); // +
        dfs(cnt+i+1, num-x, N, number); // -
        // 0이 아닐 경우에만
        if(num != 0){
            dfs(cnt+i+1, num*x, N, number); // *
            dfs(cnt+i+1, num/x, N, number); // /
        }
    }
}

int solution(int N, int number) {
    dfs(0,0,N,number);
    if(answer>8) answer = -1;
    return answer;
}