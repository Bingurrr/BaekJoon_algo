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

int testcase, n;
int charge[1500];
string ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(true){
        cin >> n;
        if(n==0){
            break;
        }
        ans = "POSSIBLE";
        for(int i = 0; i < n; i++){
            cin >> charge[i];
        }
        sort(charge, charge+n);
        for(int i = 1; i < n; i++){
            if(charge[i]-charge[i-1] <= 200) {
                continue;
            }
            else {
                ans = "IMPOSSIBLE";
                break;
            }
        }
        if(1422-charge[n-1] > 100){
            ans = "IMPOSSIBLE";
        }
        cout << ans << '\n';
        
    }
    
	return 0; 
}
