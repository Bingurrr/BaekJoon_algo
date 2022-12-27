#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x1, x2, x3;
    int y1, y2, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    
    int k = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
    if(k==0){
        cout << 0;
    }
    else if(k > 0){
        cout << 1;
    }
    else cout << -1;


    return 0;
}