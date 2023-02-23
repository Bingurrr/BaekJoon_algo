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

int n, ans;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i <= n; i++){
        int k = n;
        vector<int> tmp;
        tmp.push_back(n);
        tmp.push_back(i);
        int s = 0;
        int e = 1;
        while(tmp[s] >= tmp[e]){
            tmp.push_back(tmp[s]-tmp[e]);
            s++;
            e++;
        }
        if(ans < tmp.size()){
            ans = tmp.size();
            v = tmp;
        }
    }

    cout << ans << '\n';
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    

	return 0; 
}
