#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>

using namespace std;


bool cmp(int a, int b, int c, int d){
    if(a < c) return true;
    else if (a > c) return false;
    else return b <= d;
}

long long int CCW(long long int a1, long long int b1, long long int a2, long long int b2, long long int a3,long long int b3) {
    if(a1 * b2 + a2 * b3 + a3 * b1 - ( b1 * a2 + b2 * a3 + b3 * a1) < 0)
        return 1;
    else if(a1 * b2 + a2 * b3 + a3 * b1 - ( b1 * a2 + b2 * a3 + b3 * a1) == 0 ) return 0;
    else return -1;
}

void intersection(long long int X1, long long int Y1, long long int X2, long long int Y2, long long int X3,long long int Y3, long long int X4, long long int Y4){
	double px = (X1 * Y2 - Y1 * X2) * (X3 - X4) - (X1 - X2) * (X3 * Y4 - Y3 * X4);
	double py = (X1 * Y2 - Y1 * X2) * (Y3 - Y4) - (Y1 - Y2) * (X3 * Y4 - Y3 * X4);
	double p = (X1 - X2) * (Y3 - Y4) - (Y1 - Y2) * (X3 - X4);

	if (p == 0){
		if ((X1==X4 && Y1==Y4) && (X1>= X3 || (X1==X3 && Y1>= Y3))) cout << X1 << " " << Y1 << '\n';
		else if ((X2==X3 &&(Y2==Y3)) && (X1<=X3 && (X1==X3 || Y3 >=Y1)))  cout << X2 << " " << Y2 << '\n';
	}
	else{
		double x = px / p;
		double y = py / p;

		cout.precision(30);
		cout << x << " " << y;
	}
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);	
    long long int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    if(CCW(x1,y1,x2,y2,x3,y3)*CCW(x1,y1,x2,y2,x4,y4) ==0 &&  CCW(x3,y3,x4,y4,x1,y1)*CCW(x3,y3,x4,y4,x2,y2) ==0){
        if(x1 > x2 || (x1==x2 && y1 > y2)){
            int t1 = x1;
            int t2 = y1;
            x1 = x2;
            y1 = y2;
            x2 = t1;
            y2 = t2;
        }
        if(x3 > x4 || (x3==x4 && y3 > y4)){
            int t1 = x3;
            int t2 = y3;
            x3 = x4;
            y3 = y4;
            x4 = t1;
            y4 = t2;
        }
        if(cmp(x1,y1, x4,y4) && cmp(x3,y3,x2,y2)){
            cout << 1 << '\n';
            intersection(x1,y1,x2,y2,x3,y3,x4,y4);
        }
        else {
            cout << 0 << '\n';
        }
    }
    else {
        if(CCW(x1,y1,x2,y2,x3,y3)*CCW(x1,y1,x2,y2,x4,y4) <= 0 && CCW(x3,y3,x4,y4,x1,y1)*CCW(x3,y3,x4,y4,x2,y2) <= 0){
            cout << 1 << '\n';
            intersection(x1,y1,x2,y2,x3,y3,x4,y4);
        }
        else {
            cout << 0 << '\n';
        }
    }
	return 0; 
}