#include<bits/stdc++.h>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int N = maps.size();
    int M = maps[0].size();
    
    int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
    
    queue <pair<int,int>> q;
    int cnt[105][105]={0, };
    q.push({0,0});
    cnt[0][0]=1;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int d=0; d<4; d++){
            int nx = x+dx[d];
            int ny = y+dy[d];
            if(0>nx||nx>N-1||0>ny||ny>M-1) continue;
            if(cnt[nx][ny]!=0 && cnt[nx][ny]<=cnt[x][y]+1) continue;
            if(maps[nx][ny]==0) continue;
            q.push({nx,ny});
            cnt[nx][ny] = cnt[x][y]+1;
        }
    }
    
    if(cnt[N-1][M-1]==0) answer=-1;
    else answer=cnt[N-1][M-1];
    return answer;
}

//프로그래머스 : https://programmers.co.kr/learn/courses/30/lessons/1844
