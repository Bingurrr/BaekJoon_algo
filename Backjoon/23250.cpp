#include <stdio.h>
unsigned long long pow(int x);
int main()
{
	int n, cnt = 0;
	int from = 1, to = 3, by = 2;
	unsigned long long k, std = 0, sstd = 0;
	scanf("%d %llu", &n, &k);
	std = pow(n - 1);
	sstd = std / 2; 
	while (1) {
		if (k == std) {
			printf("%d %d\n", from, to);
			break;
		}
		else if (k < std) {
			cnt = to;
			to = by;
			by = cnt;
			std -= sstd;
		}
		else if (k > std) {
			cnt = from;
			from = by;
			by = cnt;
			std += sstd;
		}
		sstd /= 2;
	}
}
unsigned long long pow(int x)
{
	unsigned long long result = 1;
	for (int i = 0; i < x; i++)
		result *= 2;
	return result;
}
