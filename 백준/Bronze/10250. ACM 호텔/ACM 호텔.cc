#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

int t;
int a, b, c;
// stack<char> st;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> a >> b >> c;
        if(c%a!= 0)
            cout << (c%a)*100 + c/a+1 << '\n';
        else {
            cout << a*100 + (c/a) << '\n';
        }
    }
    return 0;
}