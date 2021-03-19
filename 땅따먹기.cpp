#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    for(int i = 0; i < land.size()-1 ; i++){
        land[i+1][0] += max(land[i][1],max(land[i][2],land[i][3]));
        land[i+1][1] += max(land[i][0],max(land[i][2],land[i][3]));
        land[i+1][2] += max(land[i][0],max(land[i][1],land[i][3]));
        land[i+1][3] += max(land[i][0],max(land[i][1],land[i][2]));
    }
    answer = max(land[land.size()-1][0], max(land[land.size()-1][1], max( land[land.size()-1][2], land[land.size()-1][3] )));
    return answer;
}

//프로그래머스 : https://programmers.co.kr/learn/courses/30/lessons/12913
//각 행의 땅마다 갈 수 있는 최대값을 구하여, 마지막 행에서 최댓 값을 갖는 땅이 정답
