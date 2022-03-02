#include <string>
#include <vector>

using namespace std;


int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int c = 0;
    int r = 0;
    int big, small;
    for(int i = 0; i < sizes.size(); i++){
        if(sizes[i][0] > sizes[i][1]){
            big = sizes[i][0];
            small = sizes[i][1];
        }
        else {
            big = sizes[i][1];
            small = sizes[i][0];
        }
        if(big > c) c = big;
        if(small > r) r = small;
    }
    answer = c * r;
    
    return answer;
}
