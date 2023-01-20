#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<pair<int, int>> s;

bool cmp(vector<int> a, vector<int> b){
    if(a[0]+a[1] != b[0]+b[1])
        return a[0]+a[1] > b[0]+b[1];
    else 
        return abs(a[0]-a[1]) < abs(b[0]-b[1]);
}

int solution(vector<vector<int>> scores) {
    int rank = 1;
    int x = scores[0][0] + scores[0][1]; // 완호 점수
    int x1 =  scores[0][0];
    int x2 = scores[0][1];

    sort(scores.begin(), scores.end(), cmp);
    int m = scores[0][0] + scores[0][1];
    s.push_back({scores[0][0], scores[0][1]});
    int m_x = scores[0][0];
    int m_y = scores[0][1];
    
    if(x==m) return 1;
    
    for(int i = 0; i < scores.size(); i++){
        int a = scores[i][0] + scores[i][1];
        if(scores[i][0] > m_x){
            s.push_back({scores[i][0], scores[i][1]});
            m_x = scores[i][0];
        }
        if(scores[i][1] > m_y){
            s.push_back({scores[i][0], scores[i][1]});
            m_y = scores[i][1];
        }
        if(a > x){
            rank++;
            if(a <= m-2) {
                for(auto j : s){
                    if(scores[i][0] < j.first && scores[i][1] < j.second){
                        rank--;
                        break;
                    }
                }
            }
        }
        else break;
    }
    for(auto j : s){
        if(x1 < j.first && x2 < j.second){
            return -1;
        }
    }
    
    
    return rank;
}