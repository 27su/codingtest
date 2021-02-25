// 프로그래머스 : https://programmers.co.kr/learn/courses/30/lessons/49994#

#include <string>
using namespace std;

int getD(int d){
    if(d==0) return 1;
    else if(d==1) return 0;
    else if(d==2) return 3;
    else return 2;
}

int solution(string dirs) {
    int answer = 0;
    int map[11][11]={0, };
    bool check[11][11][4]={0, };
    int x=5,y=5;
    int dx[]={-1,1,0,0}, dy[]={0,0,1,-1};
    
    for(int i=0; i<dirs.size(); i++){
        int d;
        if(dirs[i]=='U') d=0;
        else if(dirs[i]=='D') d=1;
        else if(dirs[i]=='R') d=2;
        else d=3;
        
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(0>nx||nx>10||0>ny||ny>10) continue;
        if(!check[nx][ny][d]) {
            answer++;
            check[nx][ny][d] = true;
            check[x][y][getD(d)] = true; //아마 가는 경로와 되돌아오는 경로는 같은 경우 
        }
        x = nx;
        y = ny;
    }
    return answer;
}
