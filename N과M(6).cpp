// 백준 : https://www.acmicpc.net/submit/15655

#include <bits/stdc++.h>

using namespace std;

int N,M;
vector <int> arr;
vector <int> check;
vector <int> result;

void getResult(int index, int start){
    if(index==M){
        for(int i=0; i<M; i++) printf("%d ", result[i]);
        printf("\n");
        return;
    }
    
    for(int i=start; i<N; i++){
        if(check[i]) continue;
        check[i] = true;
        result.push_back(arr[i]);
        getResult(index+1, i+1);
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
    getResult(0,0);
    return 0;
}