#include <iostream>
#define MAX_SIZE 1001

using namespace std;

int arr[MAX_SIZE];
int n;


int gcd(int a, int b) {
	if (a == 0) return b;
	else return gcd(b % a, a);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
    int t;
	for (int j = 0; j < n - 1; j++) {
		arr[j] = abs(arr[j+1] - arr[j]);
        if(arr[j] != 0) t = arr[j];
	}
	
	for (int i = 0; i < n - 2; i++) {
		int a;
		if (arr[i + 1] % t == 0) continue;
		else if(arr[i] < arr[i+1]) a = gcd(arr[i], arr[i + 1]);
		else if (arr[i] >= arr[i + 1]) a = gcd(arr[i + 1], arr[i]);
		if (t > a && a != 0) t = a;
	}
	cout << t;

	return 0;
}
