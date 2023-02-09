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
#define MAX 100000001
using namespace std;

int n, max_value;;
int arr[500001];
int ans[500001];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    arr[0] = MAX;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        int j = i-1;
        
        while(arr[j] < arr[i]){
            j = ans[j];
        }
        ans[i] = j;
    }

    for(int i = 1; i <= n; i++){
        cout << ans[i] << ' ';
    }
    
    return 0;
}
