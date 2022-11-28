#include <iostream>
#include <math.h>

using namespace std;

int main() {
	long long n;
	long long q;
	
	cin >> n;
	
	q = sqrt(n);

	if ( (q*q) < n) {
		++q;
	}

	cout << q;

	return 0;
}