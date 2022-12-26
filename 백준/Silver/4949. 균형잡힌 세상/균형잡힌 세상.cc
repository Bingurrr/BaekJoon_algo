#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

char s[101];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin.getline(s, 101)){
        int small_l=0;
        int small_r=0;
        int big_l=0;
        int big_r=0;
        stack<char> st;
        if(strlen(s)==1) break;
        for(int i = 0; i < 101; i++){
            if(s[i] == '.'){
                if(small_r!= small_l || big_r != big_l){
                    cout << "no" << '\n';
                }
                else {
                    cout << "yes" << '\n';
                }
                break;
            }
            if(s[i] == '('){
                small_l++;
                st.push('(');
            }
            else if(s[i] ==')'){
                small_r++;
                if(!st.empty() && st.top()!= '(') {
                    cout << "no" << '\n';
                    break;
                }
                st.pop();
            }
            else if(s[i]=='['){
                big_l++;
                st.push('[');
            }
            else if(s[i]==']'){
                big_r++;
                if(!st.empty() && st.top() != '['){
                    cout << "no" << '\n';
                    break;
                }
                st.pop();
            }
            if(small_r > small_l || big_r > big_l){
                cout << "no" << '\n';
                break;
            }
        }
    }
    return 0;
}