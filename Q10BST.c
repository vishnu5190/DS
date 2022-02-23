// Q10 BST
// Write a program
// a) To construct a binary Search tree.
// b) To traverse the tree using all the methods i.e., in-order, preorder and post
// order
// c) To display the elements in the tree.
#include <stdio.h>
#include <stdlib.h>

typedef struct BST{
    struct BST *left;
    struct BST *right;
    int data;
}node;

node *create(){
    node *temp;
    printf("\nEnter data : ");
    temp = (node*)malloc(sizeof(node));
    scanf("%d",&temp->data);
    temp->right=temp->left=NULL;
    return temp;
}
void insert(node *root, node *temp){
    if(temp->data>root->data){
        if(root->right!=NULL)
            insert(root->right, temp);
        else
            root->right = temp;
    }
    if(temp->data<=root->data){
        if(root->left!=NULL)
            insert(root->left, temp);
        else
            root->left = temp;
    }
}
void inorder(node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}
void postorder(node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}
void preorder(node *root){
    if(root!=NULL){
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
int main(){
    char ch;
    node *root = NULL, *temp;
    do{
        temp = create();
        if(root==NULL)
            root=temp;
        else
        insert(root,temp);
        printf("\nEnter y to continue : ");
        getchar();
        scanf("%c",&ch);
    }while(ch=='y');
    printf("\nInorder   : ");
    inorder(root);
    printf("\nPreorder  : ");
    preorder(root);
    printf("\nPostorder : ");
    postorder(root);
}