#include<stdio.h>
#include<stdlib.h>
// we will take a string of interger and creatre a binary search tree out of it

struct node{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node *noderef;

noderef createNode(int data){
    noderef newNode = (noderef)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

noderef createBSTfrompreorder(noderef root, int data){
    if(root == NULL){
        return createNode(data);
    }
    if(data < root->data){
        root->left = createBSTfrompreorder(root->left, data);
    }
    else{
        root->right = createBSTfrompreorder(root->right, data);
    }
    return root;
}

void inorderprint(noderef root){
    if(root == NULL){
        return;
    }
    inorderprint(root->left);
    printf("%d ", root->data);
    inorderprint(root->right);
}

void postorder(noderef root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void preorder(noderef root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}



int main(){
    int arr[7]={100,20,10,30,200,150,300};

    noderef root=createNode(arr[0]);
    noderef temp = root;
    
    for(int i=1; i<7; i++){
        root = createBSTfrompreorder(root, arr[i]);
    }
    inorderprint(temp);
    printf(" - inorder\n");
    preorder(temp);
    printf("- preorder\n");
    postorder(temp);
    printf("- postorder\n");
    return 1;
}