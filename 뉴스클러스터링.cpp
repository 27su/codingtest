#include <bits/stdc++.h>

using namespace std;

bool isAlpha(char ch){
    if('A'<= ch && ch <= 'Z' || 'a'<= ch && ch <= 'z') return true;
    return false;
}

void make(string str, vector<string> &v){
    for(int i=0; i<str.size()-1; i++){
        if(isAlpha(str[i]) && isAlpha(str[i+1])){
            v.push_back(str.substr(i,2));
        }
    }
}


int solution(string str1, string str2) {
    int answer = 0;
    vector<string> A;
    vector<string> B;
    
    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
    
    make(str1,A);
    make(str2,B);
    
    if(A.empty() && B.empty()) return 65536;
    
    if(A.size()<B.size()) swap(A,B);
    
    int max = A.size() + B.size();
    int min = 0;
    
    for(int i=0; i<B.size(); i++){
        auto it = find(A.begin(), A.end(), B[i]);
        if(it != A.end()){
            min++;
            A.erase(it);
        }
    }
    
    max -= min;
    
    double result = ((double)min / (double)max) * 65536;
    answer = result;
    
    return answer;
}
