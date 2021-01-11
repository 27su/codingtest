//백준 : https://www.acmicpc.net/problem/2805
#include <bits/stdc++.h>
using namespace std;

long long N,M;
vector <long long> tree;

long long result=0;

void binarySearch(long long l, long long r){
    if(l>r) return;
    long long mid = (l+r)/2;
    
    long long sum = 0;
    for(int i=N-1; i>=0; i--){
        if(tree[i]-mid>0) sum += (tree[i]-mid);
        else break;
    }
    
    if(sum>=M){
        if(result<mid) result = mid;
        binarySearch(mid+1, r);
    }
    else binarySearch(l,mid-1);
}

int main(){
    scanf("%lld %lld", &N, &M);
    
    for(int i=0; i<N; i++){
        long long temp;
        scanf("%lld", &temp);
        tree.push_back(temp);
    }
    
    sort(tree.begin(), tree.end());
    
    binarySearch(0,tree[N-1]);
    
    printf("%lld", result);
    
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;


int main(){
    long long N,M;
    vector <long long> tree;

    scanf("%lld %lld", &N, &M);
    
    for(int i=0; i<N; i++){
        long long temp;
        scanf("%lld", &temp);
        tree.push_back(temp);
    }
    
    sort(tree.begin(), tree.end());
    
    long long left=0, right=tree[N-1];
    
    while(left<=right){
        long long mid = (left+right)/2;
        long long sum = 0;
        for(int i=N-1; i>=0; i--){
            if(tree[i]>mid) sum += (tree[i]-mid);
            else break;
        }
        
        if(sum<M) right = mid-1;
        else left = mid+1;
    }
    
    printf("%lld", right);
    
    return 0;
}
*/
