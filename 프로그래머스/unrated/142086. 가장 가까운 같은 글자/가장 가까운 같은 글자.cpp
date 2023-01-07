#include <string>
#include <vector>
#include <iostream>

using namespace std;

int visited[27] = {0,};

vector<int> solution(string s) {
    vector<int> answer;
    for(int i = 0; i < s.size(); i++){
        int k = s[i] - 'a';
        cout << k << endl;
        if(visited[k] == 0) {
            visited[k] = i+1;
            answer.push_back(-1);
        }
        else {
            answer.push_back(i+1-visited[k]);
            visited[k] = i+1;
        }
        
    }
    return answer;
}