//프로그래머스 : https://programmers.co.kr/learn/courses/18/lessons/1879

#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer=board[0][0]; //주의, 0이면 안된다
    for(int i=1; i<board.size(); i++){
        for(int j=1; j<board[i].size(); j++){
            if(board[i][j]){
                board[i][j] = 1 + min({board[i-1][j-1],board[i-1][j],board[i][j-1]}); //위,대각선,왼쪽
                answer = max(answer,board[i][j]);
            }
        }
    }
    
    return answer*answer; //answer = 정사각형 한 변의길이
}
