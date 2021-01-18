// 백준 : https://www.acmicpc.net/problem/9372

#include <bits/stdc++.h>
using namespace std;

int N,M;
vector <int> plain[1005];

int getResult(){
    queue <int> q;
    bool check[1005]={0, };
    
    q.push(1);
    check[1] = true;
    
    int cnt = -1;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cnt++;
        for(int i=0; i<(int)plain[cur].size();i++){
            int next = plain[cur][i];
            if(check[next]) continue;
            q.push(next);
            check[next] = true;
        }
    }
    
    return cnt;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=0; t<T; t++){
        scanf("%d %d", &N, &M);
        for(int i=0; i<M; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            plain[a].push_back(b);
            plain[b].push_back(a);
        }
        printf("%d\n", getResult());
        //printf("%d\n", N-1);
        for(int i=1; i<=N; i++) plain[i].clear();
    }
    return 0;
}