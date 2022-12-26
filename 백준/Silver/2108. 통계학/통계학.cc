#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n;
int arr[500001];
int cnt[8002];
int sum, f, m, k, a;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        sum += a;
        arr[i] = a;
        cnt[a+4000]++;
    }
    int se = 0;
    for(int i = 0; i < 8002; i++){
        if(cnt[i] == m){
            if(se==0){
                k = i-4000;
                se = 1;
            }
        }
        else if(cnt[i] > m){
            se = 0;
            m = cnt[i];
            k = i-4000;
        }
    }

    
    sort(arr,arr+n);
    
    cout <<  int(round(double(sum)/double(n))) << '\n';
    
    if(n%2==1)
        cout << arr[n/2] << '\n';
    else 
        cout << (arr[(n-1)/2] + arr[(n+1)/2])/2 << '\n';
    cout << k << '\n';
    
    cout << arr[n-1]- arr[0];


    
    return 0;
}