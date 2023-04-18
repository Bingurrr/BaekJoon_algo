#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <cstring>
#include <set>
#include <stack>
#define INF 2000000001

using namespace std;

double x, y, c;
double h,l,ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> x >> y >> c;
    h = min(x,y);
    l = 1;
    while(l+0.001 <= h){

        double w = (l+h)/2;
        
        double h1 = sqrt(x*x-w*w);
        double h2 = sqrt(y*y-w*w);
        double new_c = (h1*h2)/(h1+h2);

        if (new_c >= c){
            ans = w;
            l = w;
        }
        else h = w;
    }

    cout.precision(30);
    cout << ans;

    return 0;
}
