#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node* next;
};
struct LinkedList {
struct Node* head;
};
void insert(struct LinkedList* list, int value) {
struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
newNode->data = value;
newNode->next = NULL;
if (list->head == NULL) {
list->head = newNode;
} else {
struct Node* temp = list->head;
while (temp->next != NULL) {
temp = temp->next;
}
temp->next = newNode;
}
}
void display(struct LinkedList list) {
struct Node* temp = list.head;
while (temp != NULL) {
printf("%d ", temp->data);
temp = temp->next;
}
printf("\n");
}
int main() {
struct LinkedList list = { .head = NULL };
insert(&list, 10);
insert(&list, 20);
insert(&list, 30);
display(list);
return 0;
}
