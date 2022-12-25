#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, a, b, k;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(a < k){
            cout << a << " ";
        }
    }
    
    return 0;
}