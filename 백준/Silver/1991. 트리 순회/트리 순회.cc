#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#define INF 987654321

using namespace std;

struct node{
    char right, left, val;
};

int n;
node arr[27];
char a, b, c;

void preorder(node k){
    // if(k.val == '*') return;
    cout << k.val;
    if(k.left != '*')
        preorder(arr[k.left - 'A']);
    if(k.right != '*')
        preorder(arr[k.right- 'A']);
}

void inorder(node k){
    // if(k.val == '*') return;
    if(k.left != '*')
        inorder(arr[k.left - 'A']);
    cout << k.val;
    if(k.right != '*')
        inorder(arr[k.right- 'A']);
}

void postorder(node k){
    // if(k.val == '*') return;
    if(k.left != '*')
        postorder(arr[k.left - 'A']);
    if(k.right != '*')
        postorder(arr[k.right- 'A']);
    cout << k.val;
}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        node x;
        x.val = a;
        if(b!= '.'){
            x.left  = b;
        }
        else{
            x.left = '*';
        }
        if(c!='.'){
            x.right = c;
        }
        else{
            x.right = '*';
        }
        arr[a-'A'] = x;
    }
    preorder(arr[0]);
    cout << '\n';
    inorder(arr[0]);
    cout << '\n';
    postorder(arr[0]);
	return 0;
}
