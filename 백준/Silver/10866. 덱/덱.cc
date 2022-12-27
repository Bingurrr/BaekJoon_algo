#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <unordered_map>
#include <string>
#include <list>
using namespace std;

int n, m, x;
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    list<int> li;
    for(int i = 0; i < n; i++){
        cin >> s;
        if(s=="push_front"){
            cin >> x;
            li.push_front(x);
        }
        else if(s=="push_back"){
            cin >> x;
            li.push_back(x);
        }
        else if(s=="front"){
            if(!li.empty())
                cout << li.front() << '\n';
            else 
                cout << -1 << '\n';
        }
        else if(s=="back"){
            if(!li.empty())
                cout << li.back() << '\n';
            else 
                cout << -1 << '\n';
        }
        else if(s=="size"){
            cout << li.size() << '\n';
        }
        else if(s=="empty"){
            cout << li.empty() << '\n';
        }
        else if(s=="pop_front"){
            if(!li.empty()){
                cout << li.front() << '\n';
                li.pop_front();
            }
            else
                cout << -1 << '\n';
        }
        else if(s=="pop_back"){
            if(!li.empty()){
                cout << li.back() << '\n';
                li.pop_back();
            }
            else
                cout << -1 << '\n';
        }
    }
    
    return 0;
}