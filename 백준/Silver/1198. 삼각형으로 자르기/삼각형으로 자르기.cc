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

double x[40];
double y[40];
int n;
double ans;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    
    for (int i = 0; i < n-2; i++) {
        for (int j = i+1; j < n-1; j++) {
            for (int k = j+1; k < n; k++) {
                double area = abs(x[j]*y[i] + x[k]*y[j] + x[i]*y[k] - x[i]*y[j] - x[j]*y[k] - x[k]*y[i]);
                ans = max(ans, area);
            }
        }
    }
    cout.precision(30);
    cout << ans/2.0;
	return 0; 
}
