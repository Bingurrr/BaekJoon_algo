#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(char a, char b){
    return a < b;
}

string solution(string my_string) {
    string answer = "";
    vector<char> v;
    //65 -> 97;
    for(int i = 0; i < my_string.size(); i++){
        if(int(my_string[i]) < 97){
            v.push_back(my_string[i] + 32);
        }
        else v.push_back(my_string[i]);
    }
    sort(v.begin(), v.end(), cmp);
    for(auto i : v){
        answer += i;
    }
    
    
    return answer;
}