#include <iostream>
#include <cmath>
#include <string>

using namespace std;


int swap(int k, string s1, string s2) {
	int ret = 0;
	int b = 0;
	int w = 0;
	int num = 0;
	for (int i = 0; i <k; i++) {
		if (s1[i] != s2[i]) {
			if (s1[i] == 'B') b++;
			else w++;
		}
	}
	if (w == 0 | b == 0) {
		return num+w+b;
	}

	while (true) {
		num++;
		w--;
		b--;
		if (w <= 0 | b <= 0) break;
	}
	return num+w+b;
}


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s1;
		string s2;
		int ret = 0;
		int k = 0;
		cin >> k;
		cin >> s1;
		cin >> s2;
		cout << swap(k, s1, s2) << endl;

	}
	return 0;

}

