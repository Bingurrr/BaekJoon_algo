#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
#define M 1234567891

using namespace std;

int n, k;
string s;
queue<int> q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        if(s=="push"){
            cin >> k;
            q.push(k);
        }
        else if(s=="pop"){
            if(!q.empty()){
                cout << q.front() << '\n';
                q.pop();
            }
            else cout << -1 << "\n";
        }
        else if(s=="size"){
            cout << q.size() << "\n";
        }
        else if(s=="empty"){
            cout << q.empty() << "\n";
        }
        else if(s=="front"){
            if(!q.empty())
                cout << q.front() << "\n";
            else {
                cout << -1 << "\n";
            }
        }
        else {
            if(!q.empty()){
                cout << q.back() << "\n";
            }
            else {
                cout << -1 << "\n";
            }
        }
    }
    
    return 0;
}