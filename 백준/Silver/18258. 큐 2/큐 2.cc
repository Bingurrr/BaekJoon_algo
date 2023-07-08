#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#define INF 2000000001

using namespace std;

int n, x;
string s;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while(n>0){
        n--;
        cin >> s;
        if(s=="push"){
            cin >> x;
            q.push(x);
        }
        else if(s=="pop"){
            if (!q.empty()){
                cout << q.front() << '\n';
                q.pop();
            }
            else {
                cout << -1 << '\n';
            }
        }
        else if(s=="size"){
            cout << q.size() << '\n';
        }
        else if(s=="empty"){
            if(!q.empty()){
                cout << 0 << '\n';
            }
            else {
                cout << 1 << '\n';
            }
        }
        else if(s=="front"){
            if(!q.empty()){
                cout << q.front() << '\n';
            }
            else {
                cout << -1 << '\n';
            }
        }
        else {
            if(!q.empty()){
                cout << q.back() << '\n';
            }
            else {
                cout << -1 << '\n';
            }
        }
        
    }

    
    return 0;
}
