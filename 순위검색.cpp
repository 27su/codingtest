//프로그래머스 : https://programmers.co.kr/learn/courses/30/lessons/72412

#include <bits/stdc++.h>

using namespace std;

vector<string> tokenize_getline(const string& data, const char delimiter = ' ') {
	vector<string> result;
	string token;
	stringstream ss(data);

	while (getline(ss, token, delimiter)) {
		if(token != "and") result.push_back(token);
	}
	return result;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector <int> db[3][2][2][2];
    for(int i=0; i<info.size(); i++){
        vector <string> temp = tokenize_getline(info[i]);
        int index1=0,index2=0,index3=0,index4=0;
        
        if(temp[0] == "java") index1=1;
        else if(temp[0] == "python") index1=2;
        
        if(temp[1] != "backend") index2=1;
        
        if(temp[2] != "junior") index3=1;
        
        if(temp[3] != "chicken") index4=1;
        
        db[index1][index2][index3][index4].push_back(stoi(temp[4]));
    }
    for(int i=0; i<3; i++)
        for(int j=0; j<2; j++)
          for(int k=0; k<2; k++)
            for(int l=0; l<2; l++)
              sort(db[i][j][k][l].begin(),db[i][j][k][l].end()); //이분탐색을 위한 정렬
    
    for(string q : query){
        vector <string> v = tokenize_getline(q);
        // 쿼리 조건에 따른 구간 정의
        int ai,bi,aj,bj,ak,bk,al,bl;

        if(v[0]=="cpp") ai=bi=0;
        else if(v[0]=="java") ai=bi=1;
        else if(v[0]=="python") ai=bi=2;
        else {ai=0; bi=2;} // '-'

        if(v[1]=="backend") aj=bj=0;
        else if(v[1]=="frontend") aj=bj=1;
        else {aj=0; bj=1;}; // '-'

        if(v[2]=="junior") ak=bk=0;
        else if(v[2]=="senior") ak=bk=1;
        else {ak=0; bk=1;} // '-'

        if(v[3]=="chicken") al=bl=0;
        else if(v[3]=="pizza") al=bl=1;
        else {al=0; bl=1;} // '-'

        int score = stoi(v[4]);
        
        // 점수가 X점 이상인 사람의 수 계산
        int ans=0;
        for(int i=ai; i<=bi; i++){
          for(int j=aj; j<=bj; j++){
            for(int k=ak; k<=bk; k++){
              for(int l=al; l<=bl; l++){
                int n = db[i][j][k][l].size();
                if(n==0) continue;

                // 이분 탐색
                auto iter = lower_bound(db[i][j][k][l].begin(),db[i][j][k][l].end(),score); //lower_bound는 찾으려 하는 key값이 "없으면" key값보다 큰 가장 작은 정수 값을 찾습니다.

                if(iter == db[i][j][k][l].end()) continue;
                ans += n-(iter-db[i][j][k][l].begin()); //배열의 첫번째 주소를 가리키는 배열의 이름을 빼면 몇 번째 인자인지 알 수 있다. 
              }
            }
          }
        }
        answer.push_back(ans);
    }
    return answer;
}
