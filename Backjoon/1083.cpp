#include <iostream>

using namespace std;

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i< n; i++){
        cin >> arr[i];
    }
    int s;
    cin >> s;
    int j=0;
    for(int i = 0; (s!=0)&&(i < n); i++){
        if(s > n-2-i){
            j = n-2;
            // cout << j << "j" << endl;
        }
        else {
            j = i+s-1;
        }
        // cout << j << " " << s << endl;
        for(j; (s>0)&&(j >=i); j--){
            if(arr[j] < arr[j+1]){
                swap(&arr[j+1], &arr[j]);
                s--;
            }
        }
    }
    for(int i= 0; i < n; i ++){
        cout << arr[i] << " ";
    }
    
}
