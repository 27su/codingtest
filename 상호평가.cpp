#include <bits/stdc++.h>

using namespace std;

string solution(vector<vector<int>> scores) {
    string result ="";
    for(int i=0; i<scores.size(); i++){
        pair<int, int> minScore = {100,0}, maxScore = {0,0};
        int sum = 0;
        for(int j=0; j<scores[i].size(); j++){
            if(minScore.first > scores[j][i]){
                minScore = {scores[j][i], 1};
            } else if(minScore.first == scores[j][i]) {
                minScore.second++;
            }
            
            if(maxScore.first < scores[j][i]){
                maxScore = {scores[j][i], 1};
            } else if(maxScore.first == scores[j][i]) {
                maxScore.second++;
            }
            sum += scores[j][i];
        }
        
        int count = scores.size();
        if(minScore.first == scores[i][i] && minScore.second == 1 || maxScore.first == scores[i][i] && maxScore.second == 1)
        {
            sum -= scores[i][i];
            count--;
            
        }
        
        double grade = (double)sum/(double)count;
        if(grade >= 90) {
            result += 'A';
        } else if(grade >= 80) {
            result += 'B';
        } else if(grade >= 70) {
            result += 'C';
        } else if(grade >= 50) {
            result += 'D';
        } else {
            result += 'F';
        }
    }
    
    return result;
}

//프로그래머스 : https://programmers.co.kr/learn/courses/30/lessons/83201?language=cpp
