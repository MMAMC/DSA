#include <stdio.h>
#define MAX 5

int pqueue[MAX];
int rear = -1;

int isFull() {
    return rear == MAX - 1;
}

int isEmpty() {
    return rear == -1;
}

void makeEmpty() {
    rear = -1;
}

void enqueue(int data) {
    if (isFull()) {
        printf("Queue is full\n");
    } else {
        int i;
        for (i = rear; i >= 0; i--) {
            if (data > pqueue[i]) {
                pqueue[i + 1] = pqueue[i];
            } else {
                break;
            }
        }
        pqueue[i + 1] = data;
        rear++;
        printf("%d added to the queue\n", data);
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("%d removed from the queue\n", pqueue[rear]);
        rear--;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are:\n");
        for (int i = rear; i >= 0; i--) {
            printf("%d ", pqueue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, data;
    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Make Empty\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                makeEmpty();
                printf("Queue is made empty\n");
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
