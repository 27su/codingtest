//백준 : https://www.acmicpc.net/problem/2748

#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    scanf("%d", &n);
    vector<long long> arr;
    arr.resize(n+1);
    arr[0]=0;
    arr[1]=1;
    for(int i=2; i<=n; i++){
        arr[i] = arr[i-1]+arr[i-2];
    }
    printf("%lld", arr[n]);
    return 0;
}
