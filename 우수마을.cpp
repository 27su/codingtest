// 백준 : https://www.acmicpc.net/problem/1949

#include <bits/stdc++.h>
using namespace std;

int N;
vector <int> p;
vector <int> graph[10005];
bool check[10005]={0, };
long long dp[10005][2]={0, };

long long getResult(int index, bool flag){
    if(dp[index][flag]) return dp[index][flag];
    int result = 0;
    check[index] = true;
    
    for(int i=0; i<graph[index].size(); i++){
        int next = graph[index][i];
        if(check[next]) continue;
        if(flag) result += getResult(next,false);
        else result += max(getResult(next,false), getResult(next,true) + p[next]);
    }
    check[index] = false;
    dp[index][flag] = result;
    return result;
}

int main() {
    
    scanf("%d", &N);
    p.push_back(0);
    for(int i=1; i<=N; i++){
        int temp;
        scanf("%d", &temp);
        p.push_back(temp);
    }
    for(int i=0; i<N-1; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    printf("%lld", max(getResult(1,false), getResult(1,true)+p[1]));
    return 0;
}
