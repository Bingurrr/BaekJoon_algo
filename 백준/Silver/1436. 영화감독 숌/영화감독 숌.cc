#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
int cnt;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 666; i < 10000666; i++){
        int k = i;
        if(cnt==n) {
            cout << i-1; 
            break;
        }
        while(k > 600){
            if(k%1000 == 666){
                cnt++;
                break;
            }
            k = k/10;
        }
    }
    
    
    return 0;
}


