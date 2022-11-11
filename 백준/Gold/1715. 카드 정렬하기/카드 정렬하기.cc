#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 2001
using namespace std;

int n,a, b;
priority_queue<int, vector<int>, greater<int>> pq;
long long int ans;
int sum = 0;
int cnt = 0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        pq.push(a);
    }
    while(!pq.empty()){
        a = pq.top();
        if(cnt ==0){
            sum = a;
            pq.pop();
            cnt=1;
        }
        else {
            sum += a;
            pq.pop();
            cnt = 0;
            pq.push(sum);
            ans += sum;
            sum = 0;
        }
    }
    cout << ans;
    
}