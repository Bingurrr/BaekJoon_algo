#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int a, b;
    

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
    if(a >= 12 && a <= 16 && b == 0){
        cout << 320;
    }
    else{
        cout << 280;
    }
    
    
    return 0;
}