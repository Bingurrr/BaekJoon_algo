#include <iostream>

using namespace std;

int main() {
	int fibo[41];
	fibo[0] = 0;
	fibo[1] = 1;
	for (int i = 2; i < 41; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	int a;
	cin >> a;
	for (int i = 0; i < a; i++) {
		int k;
		cin >> k;
		if (k == 0) {
			cout << 1 << " " << 0 << endl;
			continue;
		}
		cout << fibo[k - 1] << " " << fibo[k] << endl;
	}


}


