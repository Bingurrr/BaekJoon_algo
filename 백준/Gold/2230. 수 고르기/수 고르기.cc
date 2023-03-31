#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#define INF 2000000001

using namespace std;

int n, m, ans;
int num[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }       
    sort(num, num+n);
    ans = INF;
    int s = 0;
    int f = 0;
    while(f < n){
        if(num[f]-num[s] == m){
            ans = m;
            break;
        }
        else if(num[f]-num[s] > m){
            if(ans > num[f]-num[s]){
                ans = num[f]-num[s];
            }
            s++;
        }
        else{
            f++;
        }
    }
    cout << ans;
	return 0;
}
