#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

int n, m, x;
string s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    stack<int> st;
    for(int i = 0; i < n; i++){
        cin >> s;
        if(s=="push"){
            cin >> x;
            st.push(x);
        }
        else if(s=="top"){
            if(!st.empty())
                cout << st.top() << '\n';
            else 
                cout << -1 << '\n';
        }
        else if(s=="size"){
            cout << st.size() << '\n';
        }
        else if(s=="empty"){
            cout << st.empty() << '\n';
        }
        else if(s=="pop"){
            if(!st.empty()){
                cout << st.top() << '\n';
                st.pop();
            }
            else
                cout << -1 << '\n';
        }
        
    }
    
    return 0;
}