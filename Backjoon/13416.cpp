#include <iostream>
#include <cmath>
#include <string>

using namespace std;

//하루에 한개 주식
//산주식 마감할때 팜
//수익 안날것 같으면 안삼

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		int sum = 0;
		int money = 0;
		int stockA = 0;
		int stockB = 0;
		int stockC = 0;
		for (int j = 0; j < a; j++) {
			money = 0;
			cin >> stockA >> stockB >> stockC;		
			money = (money > stockA) ? money : stockA;
			money = (money > stockB) ? money : stockB;
			money = (money > stockC) ? money : stockC;
			sum += money;
		}
		cout << sum << endl;
	}

}

