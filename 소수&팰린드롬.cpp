// 백준 : https://www.acmicpc.net/problem/1747

#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n){
    if(n==1) return false;
    for(long long i=2; i<=n/2; i++){
        if(n%i==0) return false;
    }
    return true;
}

bool isPalindrom(vector <int> v){
    vector <int> temp = v;
    reverse(temp.begin(), temp.end());
    for(int i=0; i<(int)v.size(); i++){
        if(v[i] != temp[i]) return false;
    }
    return true;
}

vector <int> make(long long n){
    vector <int> v;
    while(n>0){
        v.push_back(n%10);
        n /=10;
    }
    reverse(v.begin(),v.end());
    return v;
}

int main() {
    long long N;
    scanf("%lld", &N);
    
    long long result=N;
    while(true){
        vector <int> v = make(result);
        if(isPalindrom(v)){
            if(isPrime(result)) break;
        }
        result++;
    }
    printf("%lld", result);
    return 0;
}