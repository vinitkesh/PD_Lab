#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node *noderef;

noderef createNode(int data)
{
    noderef newNode = (noderef)malloc(sizeof(noderef));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

noderef createTreePostorder(int postorder[], int start, int end)
{
    if (start > end)//if start is greater than end then there is no node left to be inserted
        return NULL;// so the leaf node is pointing to null

    noderef root = createNode(postorder[end]);//last elemet of postorder is the root
    
    if (start == end)//if there is only one element left then return the root
        return root;

    int i;
    for (i = end - 1; i >= start; i--){
        if (postorder[i] < root->data)
            break;
    }

    root->right = createTreePostorder(postorder, i + 1, end - 1);
    root->left = createTreePostorder(postorder, start, i);

    return root;
}

noderef createTreeInorder (int inorder[], int start, int end)
{
    printf("you can't create a tree with only inorder traversal\n");
}

//Functions

int main()
{
    int choice;
    printf("enter your choices for creating tree");
    printf("1. Create a tree in postorder\n");
    printf("2. Create a tree in preorder\n");
    printf("3. Create a tree in inorder\n");
    scanf("%d", &choice);
    printf("Enter the number of nodes in the tree\n");
            int n;
            scanf("%d", &n);int postorder[n]; int preorder[n];int inorder[n];
    switch (choice){

        case 1:
            
            printf("Enter the postorder traversal of the tree\n");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &postorder[i]);
            }
            break;
        case 2:
           
            printf("Enter the preorder traversal of the tree\n");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &preorder[i]);
            }
            break;
        case 3:
            
            printf("Enter the inorder traversal of the tree\n");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &inorder[i]);
            }
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    printf("The tree is created\n");
    printf("1. print tree in inorder\n");
    printf("2. print tree in preorder\n");
    printf("3. print tree in postorder\n");
    scanf("%d", &choice);
    switch (choice){

        case 1:
            printf("The inorder traversal of the tree is\n");
            break;
        case 2:
            printf("The preorder traversal of the tree is\n");
            break;
        case 3:
            printf("The postorder traversal of the tree is\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
    }





    return 0;
}