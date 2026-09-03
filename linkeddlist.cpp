#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Create a linked list
void create() {
    int n, value, i;
    struct Node *newNode, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }
    }

    printf("Linked list created successfully.\n");
}

// Insert at beginning
void insertBeginning() {
    int value;
    struct Node *newNode;

    printf("Enter data: ");
    scanf("%d", &value);

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = head;
    head = newNode;

    printf("Node inserted at beginning.\n");
}

// Insert at a specific position
void insertPosition() {
    int value, position, i;
    struct Node *newNode, *temp;

    printf("Enter position: ");
    scanf("%d", &position);

    printf("Enter data: ");
    scanf("%d", &value);

    if (position == 1) {
        insertBeginning();
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    temp = head;

    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node inserted at position %d.\n", position);
}

// Insert at ending
void insertEnd() {
    int value;
    struct Node *newNode, *temp;

    printf("Enter data: ");
    scanf("%d", &value);

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    printf("Node inserted at ending.\n");
}

// Delete at beginning
void deleteBeginning() {
    struct Node *temp;

    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    temp = head;
    head = head->next;

    free(temp);

    printf("Node deleted from beginning.\n");
}

// Delete at ending
void deleteEnd() {
    struct Node *temp, *prev;

    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    // Only one node
    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Node deleted from ending.\n");
        return;
    }

    temp = head;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);

    printf("Node deleted from ending.\n");
}

// Delete from a specific/middle position
void deletePosition() {
    int position, i;
    struct Node *temp, *deleteNode;

    printf("Enter position to delete: ");
    scanf("%d", &position);

    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    if (position == 1) {
        deleteBeginning();
        return;
    }

    temp = head;

    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position.\n");
        return;
    }

    deleteNode = temp->next;
    temp->next = deleteNode->next;

    free(deleteNode);

    printf("Node deleted from position %d.\n", position);
}

// Display from beginning
void displayBeginning() {
    struct Node *temp;

    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    temp = head;

    printf("Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Display at a specific position
void displayPosition() {
    int position, i;
    struct Node *temp;

    printf("Enter position: ");
    scanf("%d", &position);

    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    temp = head;

    for (i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    printf("Element at position %d = %d\n", position, temp->data);
}

// Display from ending
void displayEnd() {
    int count = 0, i;
    struct Node *temp;

    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    temp = head;

    // Count nodes
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Linked List from ending: ");

    // Print in reverse order
    for (i = count; i >= 1; i--) {
        temp = head;

        int j;
        for (j = 1; j < i; j++) {
            temp = temp->next;
        }

        printf("%d -> ", temp->data);
    }

    printf("NULL\n");
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n========== LINKED LIST MENU ==========\n");
        printf("1. Create Linked List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at Position\n");
        printf("4. Insert at Ending\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at Ending\n");
        printf("7. Delete at Position/Middle\n");
        printf("8. Display from Beginning\n");
        printf("9. Display at Position\n");
        printf("10. Display from Ending\n");
        printf("11. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;

            case 2:
                insertBeginning();
                break;

            case 3:
                insertPosition();
                break;

            case 4:
                insertEnd();
                break;

            case 5:
                deleteBeginning();
                break;

            case 6:
                deleteEnd();
                break;

            case 7:
                deletePosition();
                break;

            case 8:
                displayBeginning();
                break;

            case 9:
                displayPosition();
                break;

            case 10:
                displayEnd();
                break;

            case 11:
                printf("Program ended.\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
