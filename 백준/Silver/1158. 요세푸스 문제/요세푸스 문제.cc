#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
using namespace std;

int n, m;
queue<int> q;
long long cnt;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <=n; i++){
        q.push(i);
    }

    cout << '<';
    while(!q.empty()){
        int a = q.front();
        cnt++;
        if(cnt%m==0){
            if(q.size() != 1)
                cout << a << ", ";
            else {
                cout << a;
            }
            q.pop();
            continue;
        }
        q.pop();
        q.push(a);
    }
    cout << '>';
    return 0;
}