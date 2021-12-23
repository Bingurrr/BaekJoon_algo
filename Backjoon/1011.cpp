#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

//k이동후 k-1 k k+1
//마지막은 거리 항상 1


/*  
제곱수에서 1-> 3-> 5 : an = 2n-1
1 : 1   2 : 2
3~4 : 3
5~6 : 4
7~9 : 5
10 ~12 : 6
13 ~ 16 : 7
규칙 1 :제곱수에서 횟수 증가
규칙 2 : 제곱수 사이의 중간값에서 횟수 증가
-> 제곱수 사이[n^2 + (n+1)^2)/2] 사이에서 증가
n = sqrt(distance)
*/

int solution(int a, int b) {
	int distance = b - a;
	int z = sqrt(distance);
	int count = 0;
	if (distance == 1) return 1;
	
	if (z * z == distance) count = 2 * z - 1;
	else count = 2 * z;
	
	if (distance > z *(z+1) ) count++;
	return count;
}

int main(void) {
	int n= 0;
	int a = 0;
	int b = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", solution(a,b));

	}
}

