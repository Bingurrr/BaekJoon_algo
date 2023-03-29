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


int x;
int m,s,n;
int arr[1003];
vector<int> num;
int ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    ans = INF;
    for(int i = 0; i < m; i++){
        cin >> x;
        arr[x] = 1;
    }
    for(int i = 1; i < 1002; i++){
        if(arr[i] != 1){
            num.push_back(i);
        }
    }
    int s = num.size();
    for(int i = 0; i < s; i++){
        for(int j = 0; j < s; j++){
            for(int k = 0; k < s; k++){
                if(ans > abs(n-num[i]*num[j]*num[k])){
                    ans = abs(n-num[i]*num[j]*num[k]);
                }
            }
        }
    }
    cout << ans;
    
	return 0;
}
