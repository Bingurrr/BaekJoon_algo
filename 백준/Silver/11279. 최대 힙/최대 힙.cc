#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 2001
using namespace std;

int n,a, b;
priority_queue<int, vector<int>, less<int>> pq;


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
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else {
            pq.push(a);
        }
    }
}