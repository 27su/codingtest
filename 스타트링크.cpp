// 백준 : https://www.acmicpc.net/problem/5014
// 참고 : https://yabmoons.tistory.com/38
  
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000000;
int F, S, G, U, D;

int bfs(){
    queue <pair<int, int>> q;
    bool check[MAX+1]={0, };
    
    q.push({S,0});
    check[S] = true;
    
    while(!q.empty()){
        int pos = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(pos == G) return cnt;
        
        for(int i=0; i<2; i++){
            int next;
            if(i==0) next = pos+U;
            else next = pos-D;
            
            if(0<next && next<=F && !check[next]){
                q.push({next, cnt+1});
                check[next] = true;
            }
        }
    }
    return -1;
}

int main() {
    
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
    int result = bfs();
    if(result == -1) printf("use the stairs");
    else printf("%d", result);
    return 0;
}