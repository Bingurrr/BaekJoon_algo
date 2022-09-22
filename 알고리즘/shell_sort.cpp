#include <stdio.h>
#include <iostream>
#define MAX_SIZE 1000
using namespace std;
void ShellSort(int a[], int n);
int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; ++i)
    {
        int num;
        int a[MAX_SIZE];
        scanf("%d", &num);
        for (int j = 0; j < num; j++)
            scanf("%d", &a[j]);
        ShellSort(a, num);
    }
    return 0;
}
void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
/* Shell Sort 함수 */
void ShellSort(int a[], int n)
{
    int countCmpOps = 0; // 비교 연산자 실행 횟수
    int countSwaps = 0; // swap 함수 실행 횟수
    // Shell sort 알고리즘 구현
    int shrink = 2;
    int gap = n/shrink;
    while(gap >= 1){
        for(int i = gap; i < n; i++){
            countCmpOps++;
            for(int j = i; (j >= gap) && (a[j-gap] > a[j]); j-=gap){
                swap(&a[j], &a[j-gap]);
                countSwaps++;
                if(j-gap >= gap){
                    countCmpOps++;
                }
            }
        }
        gap /= 2;
    }
    cout << countCmpOps << " " << countSwaps << '\n';
    // printf("%d %d ", countCmpOps, countSwaps);
}
