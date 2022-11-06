#include <iostream>
#include <cmath>
#include <algorithm>
#define MAX 500001

using namespace std;

int n,m;
int arr[MAX];
long long int ans;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    long long int tmp = 0;
    int start = 0;
    int end = 0;
    while(end != n+1){
        //cout << tmp << " ";
        if(start == end){
            end++;
            if(arr[start] > m){
                start++;
            }
            tmp = arr[start];
        }
        else if(tmp > m){
            tmp -= arr[start];
            start++;
        }
        else if (tmp < m){
            if(tmp > ans) ans = tmp;
            tmp += arr[end];
            end++;
        }
        else {
            ans = tmp;
            break;
        }
    }
    //cout << '\n';
    cout << ans;
}