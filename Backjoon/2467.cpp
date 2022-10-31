#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#define MAX 2000000005

using namespace std;

int n;
int arr[100003];
int ans[2];
int a, b;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int start = 0;
    int end = n-1;
    long long int min = MAX;
    while(start < end){
        a = arr[start];
        b = arr[end];
        //cout << a << " " << b << " " << a+b << endl;
        if(abs(b+a) < min){
            ans[0] = a;
            ans[1] = b;
            min = abs(a+b);
            if(min==0) break;
            if(abs(b+a) >= abs(b+arr[start+1])){
                start++;
            }
            else end--;
        }
        else {
            if(abs(b+a) >= abs(b+arr[start+1])){
                start++;
            }
            else end--;
        }
    }
    cout << ans[0] << " " << ans[1];
}
