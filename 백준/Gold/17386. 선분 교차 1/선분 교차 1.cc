#include<iostream>
#include<algorithm>

using namespace std;


long long int CCW(long long int a1, long long int b1, long long int a2, long long int b2, long long int a3,long long int b3) {
    if(a1 * b2 + a2 * b3 + a3 * b1 - ( b1 * a2 + b2 * a3 + b3 * a1) < 0)
        return 1;
    else return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    if(CCW(x1,y1,x2,y2,x3,y3)*CCW(x1,y1,x2,y2,x4,y4) <=0 && CCW(x3,y3,x4,y4,x1,y1)*CCW(x3,y3,x4,y4,x2,y2) <=0){
        cout << 1 << '\n';
        return 0;
    }
    cout << 0 << '\n';
    return 0;
}