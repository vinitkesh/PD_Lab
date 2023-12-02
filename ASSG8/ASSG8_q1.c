//Ansafs solution

#include <stdio.h>
#include <stdlib.h>

struct tree{
    struct tree* parent;
    int data;
    struct tree* left;
    struct tree* right;
};


// GET NEW NODE

struct tree* Getnewnode(int element){
    struct tree* temp = (struct tree*)malloc(sizeof(struct tree));
    temp->data = element;
    temp->parent = NULL;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}


struct tree* Insert(struct tree* root,int element){
    
    if( root == NULL ){
        root = Getnewnode(element);
        
        return root;
    }
    else{
        if( element >= root->data ){
            struct tree* left_child = Insert(root->left,element);
            root->left = left_child;
            left_child->parent = root;
        }
        else{
            struct tree* right_child = Insert(root->right,element);
            root->right = right_child;
            right_child->parent = root;
        }
        
    }
    
    
    return root;
}


// FIND MAXIMUM

int Maximum(struct tree* root){
    if(root == NULL){
        printf("NIL\n");
    }
    struct tree* temp = root;
    
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp->data;
}

// FIND MINIMUM

int Minimum(struct tree* root){
    if(root == NULL){
        return NULL;
    }
    struct tree* temp = root;
    
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp->data;
}


// PRE ORDER
void Preorder(struct tree* root){
    if( root == NULL ){
        return;
    }
    else{
        printf("%d ",root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}

// IN ORDER
void Inorder(struct tree* root){
    if( root == NULL ){
        return;
    }
    else{
        Inorder(root->left);
        printf("%d ",root->data);
        Inorder(root->right);
    }
}

// POST ORDER

void Postorder(struct tree* root){
    if( root == NULL ){
        return;
    }
    else{
        Postorder(root->left);
        Postorder(root->right);
        printf("%d ",root->data);
        
    }
}

// SEARCH FOR AN ELEMENT

int Search(struct tree* root,int key){
    if( root == NULL ){
        return 0;
    }
    if( root->data == key ){
        return 1;
    }
    else{
        if( key > root->data ){
            return Search(root->left,key);
        }
        if( key < root->data ){
            return Search(root->right,key);
        }
        
    }
    return 0;
}



int main(){
    int quit = 0;
    struct tree* root = NULL;
    
    while( !quit ){
        char ch;
        scanf("%c",&ch);
        if( ch == 'a'){
            int num;
            scanf("%d",&num);
            
            root = Insert(root,num);
            
        }
        if( ch == 's'){
            int num;
            scanf("%d",&num);
            
            if(root!=NULL){
                int x = Search(root,num);
                if( x == 1 ){
                    printf("F\n");
                }
                else{
                    printf("N\n");
                }
            }
            
        }
        if( ch == 'x'){
            
            if(root!=NULL){
                printf("%d\n",Maximum(root));
            }
        
        }
        if( ch == 'n'){
            
            if(root!=NULL){
                printf("%d\n",Minimum(root));
            }
            
            
        }
        if( ch == 'i'){
           
            if(root!=NULL){
                Inorder(root);
                printf("\n");
            }
        
            
            
        }
        if( ch == 'p'){
            
        
            if(root!=NULL){
                Preorder(root);
                printf("\n");
            }
            
        }
        if( ch == 't'){
            
            if(root!=NULL){
                Postorder(root);
                printf("\n");
            }
            
            
        }
        if( ch == 'e'){
            quit = 1;
        }
    }
    return 1;
}
