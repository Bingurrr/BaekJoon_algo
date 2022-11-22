#include <stdio.h>
#include <iostream>
#define MAX 100001


using namespace std;

int n;
long long int b;
long long int arr[MAX];
long long int front, e, mid, cost;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> b;
    e = 10000000001;
    mid = e/2;
	for(int i = 0; i < n; i++){
		cin >> arr[i]; 
	}
    
	int idx = 0;
	while(front < mid && mid < e){
        cost = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] < mid)
                cost += (mid-arr[i])*(mid-arr[i]);
            if(cost > b ||cost < 0) {
                cost = -1;
                break;
            }
        }
        if(cost > b || cost < 0){
            e = mid;
            mid = (front+mid)/2;
        }
        else {
            front = mid;
            mid = (mid+e)/2;
        }
    }
	cout << mid;
	return 0;
}
