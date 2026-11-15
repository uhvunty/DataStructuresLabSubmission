#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode* next;
};


struct ListNode* createNode(int value) {
    struct ListNode* newNode =
        (struct ListNode*)malloc(sizeof(struct ListNode));

    newNode->val = value;
    newNode->next = NULL;

    return newNode;
}


struct ListNode* insert(struct ListNode* head, int value) {

    struct ListNode* newNode = createNode(value);

    if (head == NULL) {
        return newNode;
    }

    struct ListNode* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;

    return head;
}


struct ListNode* deleteDuplicates(struct ListNode* head) {

    struct ListNode* current = head;

    while (current != NULL && current->next != NULL) {

        if (current->val == current->next->val) {
            current->next = current->next->next;
        }
        else {
            current = current->next;
        }
    }

    return head;
}


void display(struct ListNode* head) {

    struct ListNode* temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }

    printf("NULL\n");
}


int main() {

    struct ListNode* head = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter sorted elements: ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insert(head, value);
    }

    printf("\nOriginal linked list: ");
    display(head);

    head = deleteDuplicates(head);

    printf("After removing duplicates: ");
    display(head);

    return 0;
}
