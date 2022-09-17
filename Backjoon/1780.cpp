#include <iostream>

using namespace std;
int n;
int arr[2188][2188];
int n1 =  0;
int n2 =  0;
int n3 =  0;
void is_paper(int a, int b, int c);

int main(){
    cin >> n;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            cin >> arr[i][j];
        }
    }
    is_paper(0,0,n);
    cout << n1 << " " << n2 << " " << n3;
    return 0;
    
}
void is_paper(int a, int b, int c){
    int t = arr[a][b];
    bool bl = true;
    for(int i = a; i < a+c; i++){
        for(int j = b; j < b+c; j++){
            if(arr[i][j] != t){
                bl = false;
            }
        }
    }
    int gap = c/3;
    if(!bl){
        is_paper(a,b,gap);
        is_paper(a+gap,b,gap);
        is_paper(a+gap+gap,b,gap);
        is_paper(a,b+gap,gap);
        is_paper(a,b+gap+gap,gap);
        is_paper(a+gap,b+gap,gap);
        is_paper(a+gap,b+gap+gap,gap);
        is_paper(a+gap+gap,b+gap,gap);
        is_paper(a+gap+gap,b+gap+gap,gap);
    }
    else if (t== -1){
        n1++;
    }
    else if(t==0){
        n2++;
    }
    else {
        n3++;
    }
}
