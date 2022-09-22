#include <stdio.h>
#define MAX_SIZE 1000
void bubbleSort(int a[], int n);
void bubbleSortImproved1(int a[], int n);
void bubbleSortImproved2(int a[], int n);
void copyArray(int a[], int b[], int n);
int main()
{
     int numTestCases;
     scanf("%d", &numTestCases);
     for (int i = 0; i < numTestCases; ++i)
     {
         int num;
         int a[MAX_SIZE], b[MAX_SIZE];
         scanf("%d", &num);
         for (int j = 0; j < num; j++)
             scanf("%d", &b[j]);
         copyArray(a, b, num);
         bubbleSort(a, num);
         copyArray(a, b, num);
         bubbleSortImproved1(a, num);
         copyArray(a, b, num);
         bubbleSortImproved2(a, num);
         printf("\n");
     }
     return 0;
}
void swap(int* a, int* b)
{
     int tmp = *a;
     *a = *b;
     *b = tmp;
}
/* BubbleSort 함수 */
void bubbleSort(int a[], int n)
{
    int countCmpOps = 0; // 비교 연산자 실행 횟수
    int countSwaps = 0; // swap 함수 실행 횟수
    // bubble sort 알고리즘 구현
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1-i; j++){
            countCmpOps++; 
            if(a[j] > a[j+1]){
                swap(&a[j],&a[j+1]);
                countSwaps++;
            }
        }
    }
    printf("%d %d ", countCmpOps, countSwaps);
}

/* BubbleSort 함수 - Improved Version 1 */
void bubbleSortImproved1(int a[], int n)
{
    int countCmpOps = 0; // 비교 연산자 실행 횟수
    int countSwaps = 0; // swap 함수 실행 횟수
    // bubble sort의 개선된 알고리즘 (1) 구현
    bool changed = false;
    for(int i = 0;  i < n-1; i++){
        changed = false;
        for(int j = 0; j < n-1-i; j++){
            countCmpOps++; 
            if(a[j] > a[j+1]){
                changed = true;
                swap(&a[j],&a[j+1]);
                countSwaps++;
            }
        }
        if(changed==false){
            break;
        }
    }
    printf("%d %d ", countCmpOps, countSwaps);
}
/* BubbleSort 함수 - Improved Version 2 */
void bubbleSortImproved2(int a[], int n)
{
    int countCmpOps = 0; // 비교 연산자 실행 횟수
    int countSwaps = 0; // swap 함수 실행 횟수
    // bubble sort의 개선된 알고리즘 (2) 구현
    int idx = n -1;
    int pos = 0;
    while(idx > 0){
        pos = 0;
        for(int i = 0; i < idx; i ++){
            countCmpOps++;
            if(a[i] > a[i+1]){
                pos = i;
                swap(&a[i], &a[i+1]);
                countSwaps++;
            }
        }
        idx = pos;
    }
    printf("%d %d ", countCmpOps, countSwaps);
}
void copyArray(int a[], int b[], int n)
{
    for (int i = 0; i < n; i++)
        a[i] = b[i];
}
