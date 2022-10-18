#include<iostream>
#include<stdlib.h>
#include<cmath>

//다른분 풀이를 참고하여서 풀었습니다.
//백준 hacastle
using namespace std;
int n, num;
long long mid, k;
int disk = 1;
char s[3] = { 'A', 'B', 'C' };

void hanoi(int a, int b, int c, int n, int flag)
{
	if (n <= 1) {
		cout << disk << " " << s[a-1] <<" "<< s[b-1] << '\n';
		return;
	}
	long long value = pow(2, n - 1);
	if (flag == 0) {  // mid 갱신부분 조심!!
		mid = mid - value;
	}
	else if (flag == 1) {
		mid = mid + value;
	}

	if (k < mid) {
		disk--;
		hanoi(a, c, b, n - 1, 0); // flag =0 -> 왼쪽 확장
	}
	else if (mid < k) {
		disk--;
		hanoi(c, b, a, n - 1, 1); // flag = 1 -> 오른쪽 확장
	}
	else {
		disk = n;
		hanoi(a, b, c, 1, 0);
	}

}

int main(void)
{
	while (cin >> k >> n) {
		if (n == 0 && k == 0) break;
		mid = pow(2, n);
		disk = n;
		num++;
		cout << "Case " << num << ": ";
		hanoi(1, 3, 2, n, 0);
		
	}
	return 0;
}
