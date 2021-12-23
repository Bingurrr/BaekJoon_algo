#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <math.h>
#include <cstring>

using namespace std;

string first(char *s) {
	int length = strlen(s);
	string ret = "";
	if (length % 2 == 0) {

		for (int i = 0; i < length; i += 2) {
			ret.append(1, s[i]);
		}
	}
	else {

		for (int i = 0; i < length; i += 2) {
			ret.append(1, s[i]);
		}
		for (int i = 1; i < length; i +=2) {
			ret.append(1, s[i]);
		}
			
	}



	return ret;
}

string second(char *s) {
	int length = (int)strlen(s);
	string ret = "";
	if (length  % 2 == 0) {
		for (int i = 1; i < length; i+=2) {
			ret.append(1, s[i]);
		}
	}
	else {
		for (int i = 1; i < length; i += 2) {
			ret.append(1, s[i]);
		}
		for (int i = 0; i < length; i += 2) {
			ret.append(1, s[i]);
		}
	}

	return ret;
}



int main() {
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s = "";
		cin >> s;
		char* cstr = new char[s.length() + 1];
		strcpy(cstr, s.c_str());
		cout << first(cstr) << endl;
		cout << second(cstr) << endl;
	}

}

