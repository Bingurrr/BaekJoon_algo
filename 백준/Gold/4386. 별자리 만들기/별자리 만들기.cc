#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct star{
    int x,y;
    double cost;
};

int n, cnt;
int parent[100001];
star arr[100001];
double x[101];
double y[101];
double ans;

bool cmp(star a, star b){
    return a.cost <= b.cost;
}

int find(int i){
    while(i != parent[i]){
        i = parent[i];
    }
    return i;
}   

void uni(int i, int j, double k){
    int a = find(i);
    int b = find(j);
    if(a!= b){
        if(a < b) parent[a] = b;
        else parent[b] = a;
        cnt++;
        ans += k;
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }    
    int idx = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            parent[idx] = idx;
            arr[idx].x = i;
            arr[idx].y = j;
            arr[idx].cost = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
            idx++;
        }
    }
    sort(arr, arr+idx, cmp);
    for(int i = 0; i < idx; i++){
        uni(arr[i].x, arr[i].y, arr[i].cost);
        if(cnt == n-1) break;
    }
    
    cout.precision(30);
    cout << ans;
    
}