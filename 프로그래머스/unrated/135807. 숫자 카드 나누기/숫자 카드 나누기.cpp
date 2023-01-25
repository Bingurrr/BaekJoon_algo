#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

//a에서 약수들을 구한다.

vector<int> v;
vector<int> v2;
vector<int> v3;
bool y = true;
bool y2 = true;
bool cmp(int a, int b){
    return a > b;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    sort(arrayA.begin(), arrayA.end());
    for(int i = 1; i <= sqrt(arrayA[0]); i++){
        if(arrayA[0]%i==0){
            v.push_back(i);
            v.push_back(int(arrayA[0]/i));
        }
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < v.size(); i++){
        y = true;
        for(int j = 0; j < arrayA.size(); j++){
            if(arrayA[j]%v[i] != 0 || arrayB[j]%v[i] == 0) {
                y = false;
                break;
            }
        }
        if (y==true){
            answer = v[i];
            break;
            // v3.emplace_back(v[i]);
        }
    }
    
    sort(arrayB.begin(), arrayB.end());
    for(int i = 1; i <= sqrt(arrayB[0]); i++){
        if(arrayB[0]%i==0){
            v2.push_back(i);
            v2.push_back(int(arrayB[0]/i));
        }
    }
    sort(v2.begin(), v2.end(), cmp);
    for(int i = 0; i < v2.size(); i++){
        y2 = true;
        for(int j = 0; j < arrayA.size(); j++){
            if(arrayB[j]%v2[i] != 0 || arrayA[j]%v2[i] == 0) {
                y2 = false;
                break;
            }
        }
        if (y2==true){
            if(answer < v2[i]){
                answer = v2[i];
            }
            // v3.emplace_back(v2[i]);
        }
    }
    
    // if(v3.size() > 0){
    //     for(int i = 1; i < v3.size()-1; i++){
    //         if(v3[i] == v3[i+1] || v3[i] == v3[i-1]){
    //             continue;
    //         }
    //         else {
    //             return v3[i];
    //         }
    //     }
    // }
    
    return answer;
}