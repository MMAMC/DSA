#include <stdio.h>
#include <stdlib.h>
// Node structure for a linked list
struct Node {
int data;
struct Node* next;
};
// Stack structure
struct Stack {
struct Node* top;
};
// Queue structure
struct Queue {
struct Node* front;
struct Node* rear;
};
// Function to create a new node
struct Node* createNode(int data) {
struct Node* node = (struct Node*) malloc(sizeof(struct Node));
node->data = data;
node->next = NULL;
return node;
}
// Function to initialize a stack
void initStack(struct Stack* stack) {
stack->top = NULL;
}
// Function to push an element onto a stack
void push(struct Stack* stack, int data) {
struct Node* node = createNode(data);
node->next = stack->top;

stack->top = node;
}
// Function to pop an element from a stack
int pop(struct Stack* stack) {
if (stack->top == NULL) {
return -1;
}
int data = stack->top->data;
struct Node* temp = stack->top;

stack->top = stack->top->next;

free(temp);
return data; }
// Function to initialize a queue
void initQueue(struct Queue* queue) {
queue->front = NULL;
queue->rear = NULL;
}
// Function to enqueue an element into a queue
void enqueue(struct Queue* queue, int data) {
struct Node* node = createNode(data);
if (queue->front == NULL) {
queue->front = node;
queue->rear = node;
} 
else {
queue->rear->next = node;

queue->rear = node;
}
}
// Function to dequeue an element from a queue
int dequeue(struct Queue* queue) {
if (queue->front == NULL) {
return -1;
}
int data = queue->front->data;
struct Node* temp = queue->front;

queue->front = queue->front->next;

free(temp);
if (queue->front == NULL) {
queue->rear = NULL;
}
return data;
}


// Driver code
int main() {
struct Stack stack;
initStack(&stack);
push(&stack, 10);
push(&stack, 20);
push(&stack, 30);
printf("Popped element from stack: %d\n", pop(&stack));
printf("Popped element from stack: %d\n", pop(&stack));
struct Queue queue;
initQueue(&queue);
enqueue(&queue, 10);
enqueue(&queue, 20);
enqueue(&queue, 30);
printf("Dequeued element from queue: %d\n", dequeue(&queue));
printf("Dequeued element from queue: %d\n", dequeue(&queue));
return 0;
}
