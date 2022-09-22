#include <iostream>
#include <set>
using namespace std;
int arr[9];
bool visited[9];
int n, m;

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void recursive(int b){
    if(b == m){
        for(int i = 0 ; i < m; i++){
            cout << arr[i] << " ";
        }
        cout << '\n';
    }
    else{
        for(int i = 0; i < n; i++){
            if(visited[i] ==false){
                visited[i] = true;
                arr[b] = i+1;
                recursive(b+1);
                visited[i] = false;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    recursive(0);
    return 0;
    
}
