#include <iostream>
#define MAX_SIZE 101
#define MAX_INPUT 1000000000

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

	for (int j = 0; j < n - 1; j++) {
		arr[j] = abs(arr[j+1] - arr[j]);
	}
	int t = arr[0];
	for (int i = 0; i < n - 2; i++) {
		int a;
		if (arr[i + 1] % t == 0) continue;
		else if(arr[i] < arr[i+1]) a = gcd(arr[i], arr[i + 1]);
		else if (arr[i] >= arr[i + 1]) a = gcd(arr[i + 1], arr[i]);
		if (t > a) t = a;
	}
	for (int i = 2; i <= t/2; i++) {
		if (t % i == 0) cout << i << " ";
	}
	cout << t;

	return 0;
}
