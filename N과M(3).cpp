//백준 : https://www.acmicpc.net/problem/15651

#include <bits/stdc++.h>

using namespace std;

vector <int> result;
int N,M;

void getResult(int index){
    if(index>=M){
        for(int i=0; i<M; i++) printf("%d ",result[i]);
        printf("\n");
        return;
    } 
    
    for(int i=1; i<=N; i++){
        result.push_back(i);
        getResult(index+1);
        result.pop_back();
    }
}

int main() {
    scanf("%d %d", &N, &M);
    getResult(0);
    return 0;
}