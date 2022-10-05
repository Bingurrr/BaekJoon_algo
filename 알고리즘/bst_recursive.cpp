#include <stdio.h>
#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
void insert(struct node** root, int data);
void preOrder(struct node* root);
void inOrder(struct node* root);
void postOrder(struct node* root);
int size(struct node* root);
int height(struct node* root);
int sumOfWeight(struct node* root);
int maxPathWeight(struct node* root);
void mirror(struct node** root);
void destruct(struct node** root);
void swap(struct node** n1, struct node** n2){
    node* rt = new node;
    rt->data = (*n1)->data;
    rt->left = (*n1)->left;
    rt->right = (*n1)->right;
    n1 = n2;
    n2 = &rt;
    
}
int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    while (numTestCases--)
    {
        int num, i;
        struct node* root = NULL;
        scanf("%d", &num);
        for (i = 0; i < num; i++)
        {
            int data = i+1;
            scanf("%d", &data);
            insert(&root, data);
            //cout << root->data << endl;
        }
        printf("%d\n", size(root));
        printf("%d\n", height(root)-1);
        printf("%d\n", sumOfWeight(root));
        printf("%d\n", maxPathWeight(root));
        mirror(&root);
        preOrder(root); printf("\n");
        inOrder(root); printf("\n");
        postOrder(root); printf("\n");
        destruct(&root); // BST의 모든 노드의 동적 메모리 해제
        if (root == NULL)
            printf("0\n");
        else
            printf("1\n");
    }
    return 0;
}
// 데이터 삽입(recursion)
void insert(struct node** root, int data)
{
    if((*root) == NULL){
        node *rt = new node;
        rt->data = data;
        rt->left = NULL;
        rt->right = NULL;
        *root = rt;
    }
    else {
        //cout << (*root)->data << endl;
        if((*root)->data > data){
            insert(&(*root)->left, data);
        }
        else {
            insert(&(*root)->right, data);
        }
    }
}
// 전위(preorder)탐색(recursion)
void preOrder(struct node* root)
{
    if(root == NULL) return;
    else {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }

}
// 중위(inorder)탐색(recursion)
void inOrder(struct node* root)
{
    if(root == NULL) return;
    else {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
// 후위(postorder)탐색(recursion)
void postOrder(struct node* root)
{
    if(root == NULL) return;
    else {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}
// 노드의 개수(recursion)
int size(struct node* root)
{
    int num = 0;
    if(root == NULL) return 0;
    else{
        num = 1 + size(root->left) + size(root->right);
    }
    return num;
}
// 높이(recursion)
int height(struct node* root)
{
    int h = 0;
    if(root == NULL) return 0;
    else {
        int l = height(root->left);
        int r = height(root->right);
        if(l>r) return 1 + l;
        else return 1 + r;
    }
}
// 미러 이미지로 변환하기(recursion)
void mirror(struct node** root)
{
    if((*root) == NULL){
        return;
    }
    mirror(&(*root)->left);
    mirror(&(*root)->right);
    node *rt = (*root)->left;
    (*root)->left = (*root)->right;
    (*root)->right = rt;
}
// 노드에 저장된 데이터의 값의 합 구하기(recursion)
int sumOfWeight(struct node* root)
{
    int sum = 0;
    if(root == NULL) return 0;
    else {
        sum += root->data;
        sum += sumOfWeight(root->left) + sumOfWeight(root->right);
    }
    return sum;
}
// 루트노드부터 단말노드까지의 경로 상의 데이터의 최대합(recusrion)
int maxPathWeight(struct node* root)
{
    if(root == NULL) return 0;
    else {
        int l = maxPathWeight(root->left);
        int r = maxPathWeight(root->right);
        if(l>r) return root->data + l;
        else return root->data + r;
    }
    
}
// 트리노드의 동적 메모리 해제하기(recursion)
void destruct(struct node** root)
{
    if((*root) == NULL) return;
    else {
        destruct(&(*root)->left);
        destruct(&(*root)->left);
        free(*root);
        (*root) = NULL;
    }
}
