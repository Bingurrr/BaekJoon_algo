#include <iostream>
#include <cmath>
using namespace std;

int n;
int x[1501];
int y[1501];
int ans = 0;
long long int d1, d2, d3;

long long int distance(int x1, int y1, int x2, int y2){
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

// bool is_line(int x1, int y1, int x2, int y2, int x3, int y3){
//     int n1 = x2 - x1;
//     int n2 = x3 - x1;
//     int n3 = y2 - y1;
//     int n4 = y3 - y1;
    
//     if(x2 == x1) {
//         if(x3 == x1) {
//             return true;
//         }
//         else {
//             return false;
//         }
//     }
//     else if (n1 == 0 || n2 == 0){
//         if(n1 == n2) return true;
//         else return false;
        
//     }
//     else {
//         if((n3/n1) == (n4/n2)) {
//             return true;
//         }
//         else return false;
//     }
// }


int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    for(int i = 0; i < n-2; i++){
        for(int j = i+1; j < n-1; j++){
            for(int k = j+1; k < n; k++){
                d1 = distance(x[i], y[i], x[j], y[j]);
                d2 = distance(x[i], y[i], x[k], y[k]);
                d3 = distance(x[j], y[j], x[k], y[k]);
                // cout << d1 << " " << d2 << " " << d3 << endl;
                if((d1 == d2) && (sqrt(d1)+sqrt(d2) != sqrt(d3))) {
                    ans++;
                }
                else if((d2 == d3) && (sqrt(d2)+sqrt(d3) != sqrt(d1))){
                    ans++;
                }
                else if((d1==d3) && (sqrt(d1)+sqrt(d3) !=  sqrt(d2))){
                    ans++;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
