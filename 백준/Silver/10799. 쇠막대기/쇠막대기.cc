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

string s;
int cnt, ans;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> s;

    for(int i = 0; i < s.size(); i++){
        // cout << cnt << endl;
        if(i+1 < s.size() && s[i] == '(' && s[i+1] == ')'){
            ans += cnt;
            i++;
        }
        else if(s[i] == '('){
            cnt++;
        }
        else if(s[i] == ')'){
            ans++;
            cnt--;
        }
    }
    cout << ans;
    
    return 0;
}
