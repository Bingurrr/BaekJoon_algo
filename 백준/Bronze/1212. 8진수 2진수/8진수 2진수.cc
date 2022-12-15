#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string S,result = "";
	string num[10] = { "000","001","010","011","100","101","110","111","0","0" };
	cin >> S;
	int ssize = S.size();
	for (int i = 0; i < ssize; i++) {
		result += num[S[i] - '0'];
	}
	int rsize = result.size();
	if (rsize > 1) {
		if (result[0] == '0' && result[1] == '0') {
			cout << result.substr(2, rsize - 2);
			return 0;
		}
			
		else if (result[0] == '0') {
			cout << result.substr(1, rsize);
			return 0;
		}
	}
	cout << result;
}