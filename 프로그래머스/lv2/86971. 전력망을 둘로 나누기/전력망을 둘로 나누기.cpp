#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int visited[101];
int size1, size2;

int cnt_top(vector<vector<int>> v,int k, int s){
    int cnt = 0;
    queue<int> q;
    q.push(k);
    visited[k] = 1;
    while(!q.empty()){
        cnt++;
        int x = q.front();
        visited[x] = 1;
        q.pop();
        for(int i = 0; i < v.size(); i++){
            if(i==s) continue;
            int a = v[i][0];
            int b = v[i][1];
            if(a==x && visited[b] == 0){
                q.push(b);
            }
            else if(b==x && visited[a] == 0){
                q.push(a);
            }
        }
    }
    return cnt;
};


int solution(int n, vector<vector<int>> wires) {
    int answer = 987654321;
    for(int i = 0; i < wires.size(); i++){
        int root1 = wires[i][0];
        int root2 = wires[i][1];
        for(int i = 0; i <= n; i++){
            visited[i] = 0;
        }
        size1 = cnt_top(wires, root1, i);
        for(int i = 0; i <= n; i++){
            visited[i] = 0;
        }
        size2 = cnt_top(wires, root2, i);
        if(answer > abs(size1 - size2)){
            answer = abs(size1 - size2);
        }
    }
    return answer;
}