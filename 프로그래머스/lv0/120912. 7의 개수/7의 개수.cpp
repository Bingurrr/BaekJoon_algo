#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    for(auto i : array){
        while(i>0){
            if(i%10 == 7) answer++;
            i /= 10;
        }
    }
    return answer;
}