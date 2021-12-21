//골드바흐의 추측

#include <iostream>
#include <cmath>

using namespace std;

int n;
int arr[10001] = { 0, };

bool is_prime(int a) {
	bool ret = true;
	for (int i = 2; i <= sqrt(a); i++) {
		if (a % i == 0) return false;
	}
	return true;
}

int Solution(int num) {
	if (num == 4) {
		cout << 2 << " " << 2 << endl;
		return 0;
	}
	int n1 = num / 2;
	if (n1 % 2 == 0)  n1--; 
	while (n1 > 2) {
		if (is_prime(n1) & is_prime(num - n1)) {
			cout << n1 << " " << num - n1 << endl;
			return 0;
		}
		n1 -= 2;
	}
	return 0;
}


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long int x;
		cin >> x;
		Solution(x);
	}

}
