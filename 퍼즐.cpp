// 백준 : https://www.acmicpc.net/problem/1525
// 참고 : https://yabmoons.tistory.com/75

#include <bits/stdc++.h>
using namespace std;

int result = 0;
string target = "123456780", start;
set <string> visited;

int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};

int bfs(){
    queue <pair<string,int>> q;
    q.push({start,0});
    visited.insert(start);
    
    while(!q.empty()){
        string cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(cur == target) return cnt;
        
        int zero = cur.find('0');
        int x = zero/3; //string에서의 인덱스 번호 / 한변의 길이 = x축
        int y = zero%3; //string에서의 인덱스 번호 % 한변의 길이 = ㅛ축
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(0>nx||nx>2||0>ny||ny>2) continue;
            string next = cur;
            swap(next[x*3+y], next[nx*3+ny]); //x * 한변의 길의 + y = string에서의 인덱스 번호 
            if(visited.find(next) != visited.end()) continue;
            visited.insert(next);
            q.push({next, cnt+1});
        }
    }
    return -1;
}

int main() {
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            int temp;
            scanf("%d", &temp);
            start += to_string(temp);
        }
    }
    printf("%d",bfs());
    return 0;
}