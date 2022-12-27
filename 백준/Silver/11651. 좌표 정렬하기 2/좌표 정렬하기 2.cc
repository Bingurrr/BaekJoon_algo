#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
int x, y;

struct point{
    int x, y;
};
point arr[100001];

bool cmp(point a, point b){
    if(a.y == b.y){
        return a.x < b.x;
    }
    return a.y < b.y;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i].x >> arr[i].y;
    }
    sort(arr, arr+n, cmp);
    for(int i = 0; i < n; i++){
        cout << arr[i].x << " " << arr[i].y <<'\n';
    }
    return 0;
}