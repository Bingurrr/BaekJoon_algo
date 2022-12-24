#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
int ans;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++){
        int k = i;
        int s = 0;
        while(k > 0){
            s += k%10;
            k /=10;
        }
        if(s+i ==n){
            cout << i;
            return 0;
        }
    }
    cout << 0;
    return 0;
}


