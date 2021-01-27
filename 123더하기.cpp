//백준 : https://www.acmicpc.net/problem/9095

#include <bits/stdc++.h>
using namespace std;

int N, cnt;
void getResult(int sum){
    if(sum >= N){
        if(sum==N) cnt++;
        return;
    }
    
    for(int i=1; i<=3; i++){
        getResult(sum+i);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=0; t<T; t++){
        scanf("%d", &N);
        cnt = 0;
        getResult(0);
        printf("%d\n", cnt);
    }
    return 0;
}
