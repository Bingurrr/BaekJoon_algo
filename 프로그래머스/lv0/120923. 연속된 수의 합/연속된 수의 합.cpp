#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    int k = total/num;
    for(int i = k-(num-1)/2; i <= k+num/2; i++){
        answer.push_back(i);
    }
    return answer;
}