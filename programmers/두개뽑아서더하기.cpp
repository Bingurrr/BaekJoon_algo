#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<int> numbers) {
    int num = 0;
    set<int> order;
    for (int i = 0; i < numbers.size()-1; i ++){
        for (int j = i+1; j < numbers.size(); j++){
            num = numbers[i] + numbers[j];
            order.insert(num);
        }
    }
    vector<int> answer(order.size());
    copy(order.begin(), order.end(), answer.begin());
    
    return answer;
}
