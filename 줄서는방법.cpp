#include <bits/stdc++.h>
using namespace std; 

long long factorial[21]; 
void calc(int n) { 
    factorial[0] = 1; 
    for (int i = 1; i <= n; i++) factorial[i] = factorial[i - 1] * i; 
} 

vector<int> solution(int n, long long k) { 
    calc(n); 
    vector<bool> chk(n+1, false); 
    vector<int> answer; 
    int select = 0; 
    while (answer.size() != n) { 
        for (int i = 1; i <= n; i++) { 
            if (chk[i]) continue; 
            long long num = factorial[n - 1 - select]; 
            if (k > num) { k -= num; continue; } 
            select++; 
            answer.push_back(i); 
            chk[i] = true; 
            break; 
        } 
    } 
    return answer; 
}
