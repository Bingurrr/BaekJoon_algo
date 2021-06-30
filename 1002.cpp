#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        if(x1==x2&&y1==y2){
            if(r1==r2){
                cout << -1 << endl;
                continue;
            }
            else {
                cout << 0 << endl;
                continue;
            }
        }
        double distance = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        if (distance <r1+r2 && distance > abs(r1-r2)) {
            cout << 2 << endl;
        }
        else if (distance > r1 + r2 || distance < abs(r1-r2)) {
            cout << 0 << endl;
        }
        else {
            cout << 1 << endl;
        }
    }

}
