//백준 : https://www.acmicpc.net/problem/2003

#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M,answer=0;
    scanf("%d %d", &N, &M);
    vector <int> arr;
    
    for(int i=0; i<N; i++){
        int temp;
        scanf("%d", &temp);
        arr.push_back(temp);
    }
    
    int sum=0, left=0, right=0;
    while(right<=N){
        if(sum >= M) sum-=arr[left++];
        else sum += arr[right++];
        if(sum == M) answer++;
    }
    
    printf("%d", answer);
    
    return 0;
}

/*
int main(){
    int N,M,answer=0;
    scanf("%d %d", &N, &M);
    vector <int> arr;
    
    int sum=0, index=0;
    for(int i=0; i<N; i++){
        int temp;
        scanf("%d", &temp);
        arr.push_back(temp);
        
        sum += arr[i];
        
        while(sum>M) sum -= arr[index++];
        
        if(sum==M) answer++;
    }
    
    
    printf("%d", answer);
    
    return 0;
}
*/