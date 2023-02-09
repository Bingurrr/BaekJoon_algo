#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <stack>
using namespace std;

int n, k;
// int arr[500001];
stack<pair<int,int>> st;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> k;

        while(!st.empty()){
            if(st.top().second > k){
                cout << st.top().first << ' ';
                break;
            }
            st.pop();
        }
        if(st.empty()) cout << 0 << ' ';

        st.push({i,k});
    }
    
    return 0;
}
