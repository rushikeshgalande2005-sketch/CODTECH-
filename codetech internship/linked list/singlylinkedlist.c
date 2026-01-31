#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node *next;
};

// Function prototypes
void insertAtEnd(struct Node **head, int value);
void deleteNode(struct Node **head, int value);
void displayList(struct Node *head);

// Main function
int main() {
    struct Node *head = NULL;
    int choice, value;

    do {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insertAtEnd(&head, value);
            break;

        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteNode(&head, value);
            break;

        case 3:
            displayList(head);
            break;

        case 4:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}