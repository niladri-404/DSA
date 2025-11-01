#include <stdio.h>
#include <stdlib.h>

struct Deque {
    int *arr;
    int front, rear, size;
};

// Function to create deque dynamically
void createDeque(struct Deque *dq, int size) {
    dq->size = size;
    dq->front = dq->rear = -1;
    dq->arr = (int *)malloc(size * sizeof(int));
}

// Check if deque is full
int isFull(struct Deque *dq) {
    return ((dq->front == 0 && dq->rear == dq->size - 1) ||
            (dq->front == dq->rear + 1));
}

// Check if deque is empty
int isEmpty(struct Deque *dq) {
    return (dq->front == -1);
}

// Insert element at front
void insertFront(struct Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is FULL! Cannot insert %d at front.\n", value);
        return;
    }

    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = dq->size - 1; // wrap around
    } else {
        dq->front--;
    }

    dq->arr[dq->front] = value;
    printf("%d inserted at FRONT.\n", value);
}

// Insert element at rear
void insertRear(struct Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is FULL! Cannot insert %d at rear.\n", value);
        return;
    }

    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else if (dq->rear == dq->size - 1) {
        dq->rear = 0;
    } else {
        dq->rear++;
    }

    dq->arr[dq->rear] = value;
    printf("%d inserted at REAR.\n", value);
}

// Delete element from front
void deleteFront(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is EMPTY! Cannot delete from front.\n");
        return;
    }

    int deleted = dq->arr[dq->front];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->front == dq->size - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }

    printf("%d deleted from FRONT.\n", deleted);
}

// Delete element from rear
void deleteRear(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is EMPTY! Cannot delete from rear.\n");
        return;
    }

    int deleted = dq->arr[dq->rear];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = dq->size - 1;
    } else {
        dq->rear--;
    }

    printf("%d deleted from REAR.\n", deleted);
}

// Display the deque
void display(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is EMPTY!\n");
        return;
    }

    printf("Deque elements: ");
    int i = dq->front;
    while (1) {
        printf("%d ", dq->arr[i]);
        if (i == dq->rear)
            break;
        i = (i + 1) % dq->size;
    }
    printf("\n");
}

// Main function with switch case
int main() {
    struct Deque dq;
    int choice, value, size;

    printf("Enter size of deque: ");
    scanf("%d", &size);
    createDeque(&dq, size);

    while (1) {
        printf("\n--- Double Ended Queue Menu ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert at front: ");
            scanf("%d", &value);
            insertFront(&dq, value);
            break;
        case 2:
            printf("Enter value to insert at rear: ");
            scanf("%d", &value);
            insertRear(&dq, value);
            break;
        case 3:
            deleteFront(&dq);
            break;
        case 4:
            deleteRear(&dq);
            break;
        case 5:
            display(&dq);
            break;
        case 6:
            free(dq.arr);
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
