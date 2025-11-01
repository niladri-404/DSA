#include <stdio.h>
#include <stdlib.h>

struct CircularQueue {
    int *arr;
    int front, rear, size;
};

// Function to create queue dynamically
void createQueue(struct CircularQueue *q, int size) {
    q->size = size;
    q->front = q->rear = -1;
    q->arr = (int *)malloc(size * sizeof(int));
}

// Check if queue is full
int isFull(struct CircularQueue *q) {
    return ((q->rear + 1) % q->size == q->front);
}

// Check if queue is empty
int isEmpty(struct CircularQueue *q) {
    return (q->front == -1);
}

// Insert (enqueue) element
void enqueue(struct CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is FULL! Cannot insert %d\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % q->size;
    }
    q->arr[q->rear] = value;
    printf("%d inserted into the queue.\n", value);
}

// Delete (dequeue) element
void dequeue(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is EMPTY! Nothing to delete.\n");
        return;
    }
    int deleted = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1; // Queue becomes empty
    } else {
        q->front = (q->front + 1) % q->size;
    }
    printf("%d deleted from the queue.\n", deleted);
}

// Display queue
void display(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is EMPTY!\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->arr[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % q->size;
    }
    printf("\n");
}

// Main function with switch case
int main() {
    struct CircularQueue q;
    int choice, value, size;

    printf("Enter size of circular queue: ");
    scanf("%d", &size);

    createQueue(&q, size);

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            enqueue(&q, value);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            display(&q);
            break;
        case 4:
            free(q.arr);
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}