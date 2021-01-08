//프로그래머스 : https://programmers.co.kr/learn/courses/30/lessons/60060

#include <bits/stdc++.h>
using namespace std;

// 길이가 긴 것은 무조건 뒤쪽으로
// 길이가 같을 경우 오름차순
bool comp(string a, string b) {
    if(a.length() < b.length())
        return true;

    else if(a.length() == b.length()) {
        if(a < b)
            return true;
    }

    return false;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    // 물음표가 앞에서부터 시작하는 케이스를 위해서 words를 뒤집은 데이터도 있어야 함
    vector<string> reverseWords = words;
    for(int i = 0; i < reverseWords.size(); i++) {
        reverse(reverseWords[i].begin(), reverseWords[i].end());
    }

    // comp 기준 정렬
    sort(words.begin(), words.end(), comp);
    sort(reverseWords.begin(), reverseWords.end(), comp);


    for(int i = 0; i < queries.size(); i++) {
        int lo, hi;
        int idx;
        string query = queries[i];

        // ?가 앞에서부터 시작할 때
        if(queries[i][0] == '?') {
            // 뒤집어서부터 생각
            reverse(query.begin(), query.end());
            idx = query.find_first_of('?');

            // a로 다채움
            for(int j = idx; j < query.length(); j++) {
                query[j] = 'a';
            }
            lo = lower_bound(reverseWords.begin(), reverseWords.end(), query, comp) - reverseWords.begin();


            for(int j = idx; j < query.length(); j++) {
                query[j] = 'z';
            }
            hi = upper_bound(reverseWords.begin(), reverseWords.end(), query, comp) - reverseWords.begin();

        }

        // ?가 뒤에서부터 시작할 때
        else {
            idx = query.find_first_of('?');
            for(int j = idx; j < query.length(); j++) {
                query[j] = 'a';
            }
            lo = lower_bound(words.begin(), words.end(), query, comp) - words.begin();

            for(int j = idx; j < query.length(); j++) {
                query[j] = 'z';
            }
            hi = upper_bound(words.begin(), words.end(), query, comp) - words.begin();
        }

        answer.push_back(hi-lo);
    }

    return answer;
}