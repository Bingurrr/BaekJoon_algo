#include <iostream>
#include <algorithm>
#define MAX 10001
#define sum 

using namespace std;

int n, m;
int arr[MAX];
long long int s;
long long int ans;
int front, rear;
long long int val;

bool cmp(int a, int b){
    if (a > b) return true;
    return false;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        s += arr[i];
    }
    cin >> m;

    sort(arr, arr+n, cmp);
    rear = arr[0] + 1;
    front = 0;
    ans = s/n;
    val = m;
    while(true){
        s = 0;
        for(int i = 0; i < n; i++){
            if(ans < arr[i]) s += ans;
            else s += arr[i];
        }
        if (s<m&&ans+1 == rear) break;
        
        if(s < m) {
            front = ans;
            ans = (ans + rear) / 2;
        }
        else if (s > m){
            rear = ans;
            ans = (front + ans) / 2;
        }
        else break;
        val = s;
    }
    
    
    cout << ans;
    
}