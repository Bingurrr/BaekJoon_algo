#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

int n;
char s[51];
// stack<char> st;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        bool b = true;
        stack<char> st;
        int l = 0;
        int r = 0;
        for(int j = 0; j < strlen(s); j++){
            if(strlen(s)%2==1){
                b = false;
                break;
            }
            if(s[j] =='('){
                st.push('(');
                l++;
            }
            else{
                r++;
                if(!st.empty())
                    st.pop();
                else{
                    b = false;
                    break;
                }
            }
        }
        if(b ==true && l == r){
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}