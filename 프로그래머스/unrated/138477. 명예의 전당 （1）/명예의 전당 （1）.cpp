#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    for(auto i : score){
        pq.push(i);
        if(pq.size() > k){
            pq.pop();
        }
        answer.emplace_back(pq.top());
    }
    return answer;
}