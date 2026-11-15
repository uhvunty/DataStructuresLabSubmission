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


struct ListNode* removeValue(struct ListNode* head, int target) {


    while (head != NULL && head->val == target) {

        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }

    struct ListNode* current = head;

    while (current != NULL && current->next != NULL) {

        if (current->next->val == target) {

            struct ListNode* temp = current->next;

            current->next = current->next->next;

            free(temp);
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

    int n, value, target;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter linked list elements: ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insert(head, value);
    }

    printf("Enter value to remove: ");
    scanf("%d", &target);

    printf("\nOriginal linked list: ");
    display(head);

    head = removeValue(head, target);

    printf("After removing value: ");
    display(head);

    return 0;
}
