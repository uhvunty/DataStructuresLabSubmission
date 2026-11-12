#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void delete_begin() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty\n");
    }
    else {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void delete_end() {
    struct node *temp, *prev;

    if (head == NULL) {
        printf("List is empty\n");
    }
    else if (head->next == NULL) {
        free(head);
        head = NULL;
    }
    else {
        temp = head;

        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;
        free(temp);
    }
}

void delete_pos() {
    struct node *temp, *prev;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (head == NULL || pos < 1) {
        printf("Invalid position\n");
    }
    else if (pos == 1) {
        temp = head;
        head = head->next;
        free(temp);
    }
    else {
        temp = head;

        for (i = 1; i < pos && temp != NULL; i++) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("Invalid position\n");
        }
        else {
            prev->next = temp->next;
            free(temp);
        }
    }
}

void display() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty\n");
    }
    else {
        temp = head;

        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Delete at beginning");
        printf("\n2. Delete at end");
        printf("\n3. Delete at position");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                delete_begin();
                break;

            case 2:
                delete_end();
                break;

            case 3:
                delete_pos();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}