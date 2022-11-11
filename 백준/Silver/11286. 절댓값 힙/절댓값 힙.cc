#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 2001
using namespace std;

int n,a, b;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while(cin >> a){
        if(a == 0) {
            if(pq.empty()) {
                cout << 0 << '\n';
            }
            else {
                cout << pq.top().second << '\n';
                pq.pop();
            }
        }
        else {
            pq.push(make_pair(abs(a),a));
        }
    }
}