#include <iostream>
#include <algorithm>
#include <queue>

#define MAX 32001
using namespace std;

int n, a;
priority_queue<int ,vector<int>, greater<int>> pq;
long long int cnt, ans;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a;
            if(cnt < n){
                pq.push(a);
                cnt++;
            }
            else {
                if(a > pq.top()) {
                    pq.pop();
                    pq.push(a);
                }
            }
        }
    }

    cout << pq.top();
}