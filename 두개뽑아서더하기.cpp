//프로그래머스 : https://programmers.co.kr/learn/courses/30/lessons/68644?language=cpp

#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for(int i=0; i<numbers.size(); i++){
        for(int j=i+1; j<numbers.size(); j++){
            int sum = numbers[i]+numbers[j];
            if(find(answer.begin(), answer.end(), sum) == answer.end()) answer.push_back(sum);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
