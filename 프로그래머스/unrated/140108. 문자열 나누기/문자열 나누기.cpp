#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int idx = 0;
    while(true){
        char k = s[idx];
        int a = 0;
        int b = 0;
        for(int i = idx; i < s.size(); i++){
            if(s[i] == k){
                a++;
            }
            else b++;
            if(a==b) {
                idx = i+1;
                answer++;
                break;
            }
            if(i== s.size()-1) {
                idx = s.size();
                answer++;
            }
        }
        if(idx >= s.size()) break;
    }
    return answer;
}