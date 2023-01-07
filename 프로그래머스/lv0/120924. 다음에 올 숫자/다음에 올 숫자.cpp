#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;
    int k;
    if(common[0] - common[1] == common[1] - common[2]){
        int k = common[1] - common[0];
        cout << k << endl;
        
        return common[common.size()-1] + k;
    }
    else {
        if(common[0] == 0 || common[1] == 0) return 0;
        else {
            return common[common.size()-1] * (common[1]/common[0]);
        }
    }
    return answer;
}