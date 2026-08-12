//in stack add and delete a number
#include <stdio.h>
#include <stdlib.h> // Needed for exit(0)
#include <stdbool.h>

int main() {
    int n = 5;
    int stack[n];
    int top = -1;
    int value;
    int choice;

    while(true) {
        printf("\n1. Add | 2. Delete | 3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                if(top >= n-1) {
                    printf("Stack is full!\n");
                } else {
                    printf("Enter value to add: ");
                    scanf("%d", &value);
                    top++;
                    stack[top] = value;
                    printf("Successfully added %d to the stack\n", value);
                }
                break;

            case 2:
                if(top < 0) {
                    printf("Stack is empty\n");
                } else {
                    int deleted_value = stack[top]; 
                    printf("Successfully deleted %d from the stack\n" deleted_value);
                    top--;                          
                }
                break;

            case 3:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    }

#Queue
#include <stdio.h>
#include <stdlib.h> // Needed for exit(0)

int main() {
    int n = 5;       // Maximum capacity of the queue
    int queue[n];
    int front = -1;  // Tracks deletion index
    int rear = -1;   // Tracks insertion index
    int choice;
    int value;

    while (1) {
        printf("\n1. Add (Enqueue) | 2. Delete (Dequeue) | 3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // --- Addition Logic (Enqueue) ---
                if (rear >= n - 1) {
                    printf("Queue Overflow! Cannot add more elements.\n");
                } else {
                    printf("Enter value to add: ");
                    scanf("%d", &value);
                    
                    // If inserting the very first element, set front to 0
                    if (front == -1) {
                        front = 0;
                    }
                    
                    rear++;
                    queue[rear] = value;
                    printf("Successfully added %d to the queue\n", value);
                }
                break;

            case 2: // --- Deletion Logic (Dequeue) ---
                if (front == -1 || front > rear) {
                    printf("Queue Underflow! Queue is empty.\n");
                } else {
                    int deleted_value = queue[front];
                    printf("Successfully deleted %d from the queue\n", deleted_value);
                    front++; // Move front forward to delete the item
                    
                    // If queue becomes empty after this deletion, reset pointers
                    if (front > rear) {
                        front = -1;
                        rear = -1;
                    }
                }
                break;

            case 3:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Choose 1, 2, or 3.\n");
        }
    }
