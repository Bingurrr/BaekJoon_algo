#include <iostream>
#include <queue>
#include <algorithm>
#define MAX_SIZE 5001

using namespace std;

int arr[MAX_SIZE];
long long int n, ans;

int main(int argc, char** argv) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    for(int j = 2; j <= n-1; j++){
        int pivot = arr[j];
        int cnt = 0;
        priority_queue<int> pq;
        for(int i = 1; i < j; i++){
            pq.push(arr[i]);
        }
        int l = 1;
        while(!pq.empty()){
            int k = pq.top();
            pq.pop();
            if(k < pivot){
                ans += k-j+l;
            }
            l++;
        }
    }
    cout << ans;

	return 0;
}
