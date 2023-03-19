#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <cstring>
#include <set>
#define INF 1000002

using namespace std;

int t;
priority_queue<int> max_value;
priority_queue<int,vector<int>,greater<int>> min_value;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    
    while (t--) {
        int x;
        cin >> x;
        if (max_value.size() == min_value.size()) {
            max_value.push(x);
        }
        else {
            min_value.push(x);
        }
        if (!max_value.empty()&&!min_value.empty()&&max_value.top()>min_value.top()) {
            int max_value_val, min_value_val;
            max_value_val = max_value.top();
            min_value_val = min_value.top();
            max_value.pop();
            min_value.pop();
            max_value.push(min_value_val);
            min_value.push(max_value_val);


        }
        cout << max_value.top() << '\n';
    }
    
	return 0; 
}
