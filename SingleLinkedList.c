#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* next;
};

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
/*
Pseudocode:
1. Set a temporary pointer to the head of the list
2. Traverse the list until the end is reached
3. Print the data of the current node
4. Move to the next node
5. Print a newline character at the end of the list
*/

// Function to insert a new node at the front of the linked list
void insertAtFront(struct Node** headRef, char newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
}
/*
Pseudocode:
1. Allocate memory for the new node
2. Set the data of the new node to the given data
3. Set the next pointer of the new node to the current head of the list
4. Set the head of the list to the new node
*/
//////////////////////////////////////////////////////////////////////////////////////////////
// Function to insert a new node at the back of the linked list
void insertAtBack(struct Node** headRef, char newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

/*
Pseudocode:
1. Allocate memory for the new node
2. Set the data of the new node to the given data
3. Set the next pointer of the new node to NULL
4. If the list is empty, set the head of the list to the new node and return
5. Set a temporary pointer to the head of the list
6. Traverse the list until the end is reached
7. Set the next pointer of the last node to the new node
*/
//////////////////////////////////////////////////////////////////////////////////////////////
// Function to delete the first node of the linked list
void deleteFromFront(struct Node** headRef) {
    if (*headRef == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *headRef;
    *headRef = temp->next;
    free(temp);
}
    /*
    Pseudocode:
    1. If the list is empty, print an error message and return
    2. Set a temporary pointer to the head of the list
    3. Set the head of the list to the next node
    4. Free the memory of the deleted node
    */
//////////////////////////////////////////////////////////////////////////////////////////////
// Function to delete the last node of the linked list
void deleteFromBack(struct Node** headRef) {
    if (*headRef == NULL) {
        printf("List is empty\n");
        return;
    }
    if ((*headRef)->next == NULL) {
        free(*headRef);
        *headRef = NULL;
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}
/*
Pseudocode:
1. If the list is empty, print an error message and return
2. If the list has only one node, delete it and set the head of the list to NULL
3. Set a temporary pointer to the head of the list
4. Traverse the list until the second last node is reached
5. Free the memory of the last node
6. Set the next pointer of the second last node to NULL
*/
//////////////////////////////////////////////////////////////////////////////////////////////
// Function to search for a node with the given data in the linked list
void search(struct Node* head, char key) {
    struct Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("%c found at position %d\n", key, pos);
            return;
        }
        pos++;
        temp = temp->next;
    }
    printf("%c not found in list\n", key);
}
/*
Pseudocode:
1. Set a temporary pointer to the head of the list
2. Set a position counter to 1
3. Traverse the list until the end is reached or the node with the given data is found
4. If the data of the current node matches the given data, print the position and return
5. Increment the position counter and move to the next node
6. If the node with the given data is not found, print an error message
*/

// Function to search for a node with the given data and delete it from the linked list
void searchAndDelete(struct Node** headRef, char key) {
    struct Node* temp = *headRef;
    struct Node* prev = NULL;
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("%c not found in list\n", key);
        return;
    }
    if (prev == NULL) {
        *headRef = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("%c deleted from list\n", key);
}
/*
Pseudocode:
1. Set a temporary pointer to the head of the list
2. Set a previous pointer to NULL
3. Traverse the list until the end is reached or the node with the given data is found
4. If the node with the given data is not found, print an error message and return
5. If the node with the given data is the first node, set the head of the list to the next node
6. Otherwise, set the next pointer of the previous node to the next node of the current node
7. Free the memory of the deleted node
8. Print a message indicating that the node has been deleted
*/

// Function to sort the linked list in ascending order
void sortList(struct Node** headRef) {
    struct Node* temp1 = *headRef;
    while (temp1 != NULL) {
        struct Node* temp2 = temp1->next;
        while (temp2 != NULL) {
            if (temp1->data > temp2->data) {
                char tempData = temp1->data;
                temp1->data = temp2->data;
                temp2->data = tempData;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}
/*
Pseudocode:
1. Set a temporary pointer to the head of the list
2. Traverse the list until the end is reached
3. Set a second temporary pointer to the node after the current node
4. Traverse the list from the second node after the current node until the end is reached
5. If the data of the current node is greater than the data of the next node, swap their data
6. Move to the next node
7. Move to the next node
*/

// Main function
int main() {
    // Set the head of the list to NULL
    struct Node* head = NULL;
    // Declare variables for user input
    char choice, data;
    // Loop until the user chooses to exit
    while (1) {
        // Print the menu options
        printf("1. Insert at front  ");
        printf("2. Insert at back\n");
        printf("3. Delete from front  ");
        printf("4. Delete from back\n");
        printf("5. Search\n");
        printf("6. Search and delete  ");
        printf("7. Print list\n");
        printf("8. Sort list\n");
        printf("9. Exit\n");
        // Get the user's choice
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        // Perform the corresponding operation based on the user's choice
        switch (choice) {
            case '1':
                printf("Enter data to insert: ");
                scanf(" %c", &data);
                insertAtFront(&head, data);
                break;
            case '2':
                printf("Enter data to insert: ");
                scanf(" %c", &data);
                insertAtBack(&head, data);
                break;
            case '3':
                deleteFromFront(&head);
                break;
            case '4':
                deleteFromBack(&head);
                break;
            case '5':
                printf("Enter data to search: ");
                scanf(" %c", &data);
                search(head, data);
                break;
            case '6':
                printf("Enter data to delete: ");
                scanf(" %c", &data);
                searchAndDelete(&head, data);
                break;
            case '7':
                printList(head);
                break;
            case '8':
                sortList(&head);
                printf("List sorted in ascending order\n");
                break;
            case '9':
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
