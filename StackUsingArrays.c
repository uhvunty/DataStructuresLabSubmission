#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push()
{
    int value;

    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("Enter value to add to the stack: ");
        scanf("%d", &value);

        top++;
        stack[top] = value;

        printf("%d pushed onto the stack\n", value);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Value %d is removed from the stack\n", stack[top]);
        top--;
    }
}

void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");

    for (i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }

    printf("\n");
}

int main()
{
    int choice;

        printf("1. Push to the stack\n");
        printf("2. Pop from the stack\n");
        printf("3. Display elements from the stack\n");
        printf("4. Exit\n");


    while (1)
    {
        printf("\nEnter your choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
