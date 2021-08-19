#include <bits/stdc++.h>

using namespace std;

vector<string> answer;
map <string, string> user;
vector<string> order;

vector<string> tokenize_getline(const string& data, const char delimiter = ' ') {
	vector<string> result;
	string token;
	stringstream ss(data);

	while (getline(ss, token, delimiter)) {
		if(token != "and") result.push_back(token);
	}
	return result;
}

void changeName(string id, string newName){
    for(int j=0; j<order.size(); j++){
        if(order[j] == id){
            string before = user[id];
            answer[j].replace(0,before.length(),newName);
        }
    }
    user[id] = newName;
}


vector<string> solution(vector<string> record) {
    
    for(int i=0; i<record.size(); i++){
        vector <string> result = tokenize_getline(record[i]);
        if(result[0] == "Enter"){
            if(user.find(result[1]) != user.end()){
                changeName(result[1], result[2]);
            } else {
                user.insert({result[1], result[2]});
            }
            answer.push_back(result[2]+"님이 들어왔습니다.");
            order.push_back(result[1]);
        } else if(result[0] == "Leave"){
            answer.push_back(user[result[1]]+"님이 나갔습니다.");
            order.push_back(result[1]);
        } else{
            changeName(result[1], result[2]);
        }
    }
    return answer;
}
