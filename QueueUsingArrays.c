#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void insert()
{
    int item;

    if (rear == MAX - 1)
    {
        printf("Queue Overflow");
    }
    else
    {
        printf("Enter the element to insert: ");
        scanf("%d", &item);

        if (front == -1)
        {
            front = 0;
        }

        rear++;
        queue[rear] = item;

        printf("%d inserted into the queue", item);
    }
}

void delete()
{
    if (front == -1)
    {
        printf("Queue Empty\n");
    }
    else
    {
        printf("Deleted element: %d", queue[front]);
        front++;

        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue Empty");
    }
    else
    {
        printf("Queue elements are: ");

        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }

    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- QUEUE MENU ---");
        printf("1.Insert    ");
        printf("2.Delete    ");
        printf("3.Display   ");
        printf("4.Exit  ");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program...");
                return 0;

            default:
                printf("Invalid choice");
        }
    }

    return 0;
}
