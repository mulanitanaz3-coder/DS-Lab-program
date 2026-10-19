
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create() {
    int n, i, value;
    struct Node *newNode, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter data: ");
        scanf("%d", &value);

        newNode = (struct Node *)malloc(sizeof(struct Node));

        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }

        newNode->data = value;

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            temp = head;

            while (temp->next != head)
                temp = temp->next;

            temp->next = newNode;
            newNode->next = head;
        }
    }

    printf("Circular linked list created.\n");
}

void insertBeginning() {
    int value;
    struct Node *newNode, *temp;

    printf("Enter data: ");
    scanf("%d", &value);

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        temp = head;

        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    printf("Node inserted at beginning.\n");
}

void insertPosition() {
    int value, position, i;
    struct Node *newNode, *temp;

    printf("Enter position: ");
    scanf("%d", &position);

    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        insertBeginning();
        return;
    }

    if (head == NULL) {
        printf("Invalid position.\n");
        return;
    }

    temp = head;

    for (i = 1; i < position - 1 && temp->next != head; i++)
        temp = temp->next;

    if (i != position - 1) {
        printf("Invalid position.\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &value);

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node inserted at position %d.\n", position);
}

void insertEnd() {
    int value;
    struct Node *newNode, *temp;

    printf("Enter data: ");
    scanf("%d", &value);

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    printf("Node inserted at ending.\n");
}

void deleteBeginning() {
    struct Node *temp, *last;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    if (head->next == head) {
        head = NULL;
        free(temp);
    } else {
        last = head;

        while (last->next != head)
            last = last->next;

        head = head->next;
        last->next = head;
        free(temp);
    }

    printf("Node deleted from beginning.\n");
}

void deleteEnd() {
    struct Node *temp, *prev;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        temp = head;

        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = head;
        free(temp);
    }

    printf("Node deleted from ending.\n");
}

void deletePosition() {
    int position, i;
    struct Node *temp, *del;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter position to delete: ");
    scanf("%d", &position);

    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        deleteBeginning();
        return;
    }

    temp = head;

    for (i = 1; i < position - 1 && temp->next != head; i++)
        temp = temp->next;

    if (i != position - 1 || temp->next == head) {
        printf("Invalid position.\n");
        return;
    }

    del = temp->next;
    temp->next = del->next;
    free(del);

    printf("Node deleted from position %d.\n", position);
}

void display() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    printf("Circular Linked List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n===== CIRCULAR LINKED LIST MENU =====\n");
        printf("1. Create\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at Position\n");
        printf("4. Insert at Ending\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at Ending\n");
        printf("7. Delete at Position\n");
        printf("8. Display\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create(); break;
            case 2: insertBeginning(); break;
            case 3: insertPosition(); break;
            case 4: insertEnd(); break;
            case 5: deleteBeginning(); break;
            case 6: deleteEnd(); break;
            case 7: deletePosition(); break;
            case 8: display(); break;
            case 9:
                printf("Program ended.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
