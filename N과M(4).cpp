//백준 : https://www.acmicpc.net/problem/15652

#include <bits/stdc++.h>

using namespace std;

vector <int> result;
int N,M;

void getResult(int index, int start){
    if(index>=M){
        for(int i=0; i<M; i++) printf("%d ",result[i]);
        printf("\n");
        return;
    } 
    
    for(int i=start; i<=N; i++){
        result.push_back(i);
        getResult(index+1, i);
        result.pop_back();
    }
}

int main() {
    scanf("%d %d", &N, &M);
    getResult(0, 1);
    return 0;
}