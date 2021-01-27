//백준 : https://www.acmicpc.net/problem/1676

#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    scanf("%d", &N);
    
    int cnt=0;
    
    // 소인수분해 이용
    
    for(int i=5; i<=N; i*=5) cnt += N/i;
    
    printf("%d", cnt);
    return 0;
}
