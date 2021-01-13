// 백준 : https://www.acmicpc.net/problem/15654
#include <bits/stdc++.h>

using namespace std;

int N,M;
vector <int> arr;
vector <int> check;
vector <int> result;

void getResult(int index){
    if(index==M){
        for(int i=0; i<M; i++) printf("%d ", result[i]);
        printf("\n");
        return;
    }
    
    for(int i=0; i<N; i++){
        if(check[i]) continue;
        check[i] = true;
        result.push_back(arr[i]);
        getResult(index+1);
        result.pop_back();
        check[i] = false;
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        int temp;
        scanf("%d", &temp);
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    check.assign(N+1,0);
    getResult(0);
    return 0;
}