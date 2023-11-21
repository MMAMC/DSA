#include <stdio.h>
#define MAX_SIZE 100
struct ArrayList {
int arr[MAX_SIZE];
int size;
};
void insert(struct ArrayList *list, int value) {
if (list->size < MAX_SIZE)
list->arr[list->size++] = value;
else
printf("List is full.\n");
}
void display(struct ArrayList list) {
for (int i = 0; i < list.size; i++) {
printf("%d\n", list.arr[i]);
}
}
int main() {
struct ArrayList list = { .size = 0 };
insert(&list, 10);
insert(&list, 20);
insert(&list, 30);
display(list);
return 0;
}
