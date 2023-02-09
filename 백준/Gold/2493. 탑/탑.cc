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
                break;
            }
            st.pop();
        }

        cout << (st.empty()?0:st.top().first) << ' ';

        st.push({i,k});
    }
    
    return 0;
}
