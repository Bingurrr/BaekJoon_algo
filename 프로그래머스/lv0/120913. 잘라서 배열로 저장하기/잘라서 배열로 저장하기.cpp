#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    for(int i = 0; i < my_str.size(); i = i){
        if(i + n < my_str.size()){
            answer.push_back(my_str.substr(i,n));
            i+=n;
        }
        else {
            answer.push_back(my_str.substr(i,my_str.size()-i));
            break;
        }
    }
    return answer;
}