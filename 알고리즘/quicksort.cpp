#include <iostream>

using namespace std;

int t, n;
int arr_lomuto[1001];
int arr_hoare[1001];
int ret[4];


void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partion_lomuto(int low, int high){
    int i, j;
    int pivot;
    pivot = arr_lomuto[low];
    j = low;
    i = low+1;
    while(i <= high){
        ret[3]++;
        if(arr_lomuto[i] < pivot){
            j++;
            swap(&arr_lomuto[i], &arr_lomuto[j]);
            ret[1]++;
        }
        i++;
    }
    swap(&arr_lomuto[low], &arr_lomuto[j]);
    ret[1]++;
    return j;
}

int partition_hoare(int low, int high){
    int i, j;
    int pivot = arr_hoare[low];
    i = low -1;
    j = high + 1;
    while(true){
        while(arr_hoare[++i] < pivot) ret[2]++;
        ret[2]++;
        while(arr_hoare[--j] > pivot) ret[2]++;
        ret[2]++;
        if(i < j) {
            swap(&arr_hoare[i], &arr_hoare[j]);
            ret[0]++;
            }
        else return j;
    }
}

void quicksort_lomuto(int low, int high){
    if(low >= high) return;
    int pivot = partion_lomuto(low, high);
    quicksort_lomuto(low, pivot-1);
    quicksort_lomuto(pivot+1, high);
}

void quicksort_hoare(int low, int high){
    if(low >= high) return;
    int pivot = partition_hoare(low, high);
    quicksort_hoare(low, pivot);
    quicksort_hoare(pivot+1, high);
}




int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> arr_lomuto[j];
            arr_hoare[j] = arr_lomuto[j];
        }
        quicksort_hoare(0,n-1);
        quicksort_lomuto(0,n-1);
        for(int k = 0; k < 4; k++){
            cout << ret[k] << " ";
            ret[k] = 0;
        }
        cout << endl;
        // for(int s = 0; s < n; s++){
        //     cout << arr_lomuto[s] << " ";
        // }
        //cout << endl;

        
    }
    return 0;
}
