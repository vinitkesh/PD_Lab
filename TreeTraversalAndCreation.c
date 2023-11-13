#include <stdio.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node noderef;

noderef createNode(int data)
{
    noderef newNode = (noderef)malloc(sizeof(noderef));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

noderef createTreePostorder(int postorder[], int n)
{
    noderef root = createNode(postorder[n - 1]);
    noderef temp = root;

    for (int i = n - 2; i >= 0; i--)
    {
        
    }
    return root;
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
            scanf("%d", &n);
    switch (choice){

        case 1:
            int postorder[n];
            printf("Enter the postorder traversal of the tree\n");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &postorder[i]);
            }
            break;
        case 2:
            int preorder[n];
            printf("Enter the preorder traversal of the tree\n");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &preorder[i]);
            }
            break;
        case 3:
            int inorder[n];
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





    return 0;
}